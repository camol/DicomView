#include "dicomitem.h"

DicomItem::DicomItem(const dicom::DataSet &dset):
        iPixelData(dset(dicom::TAG_PIXEL_DATA))
{
    dset(dicom::TAG_IMAGE_TYPE) >> Img_Type;
    dset(dicom::TAG_SOP_CLASS_UID) >> SOP_Class_UID;
    dset(dicom::TAG_SOP_INST_UID ) >> SOP_Instance_UID;
    dset(dicom::TAG_STUDY_DATE ) >> Study_Date;
    dset(dicom::TAG_SERIES_DATE ) >> Series_Date;
    dset(dicom::TAG_ACQUISITION_DATE ) >> Acquisition_Date;
    //dset(dicom::TAG_SOP_INST_UID ) >> Content_Date; nie wiem ktory to TAG
    dset(dicom::TAG_STUDY_TIME ) >> Study_Time;
    dset(dicom::TAG_SERIES_TIME ) >> Series_Time;
    dset(dicom::TAG_ACQUISITION_TIME ) >> Acquisition_Time;
    dset(dicom::TAG_SERIES_TIME ) >> Content_Time;
    dset(dicom::TAG_SERIES_TIME ) >> Accession_Number;
    dset(dicom::TAG_MODALITY  ) >> Modality;
    dset(dicom::TAG_MANUFACTOR ) >> Manufacturer;
    //dset(dicom::TAG_INSTITUT_DEPT_NAME ) >> Institution_Name;
    dset(dicom::TAG_STUDY_DESC ) >> Study_Description;
    dset(dicom::TAG_STATION_NAME ) >> Station_Name;
    dset(dicom::TAG_SERIES_DESC ) >> Series_Description;
    //dset(dicom::TAG_PERF_PHYS_NAME ) >> Performing_Physicians_Name;
    //dset(dicom::TAG_OPERATOR_NAME ) >> Operators_Name; brak typu
    dset(dicom::TAG_MANFAC_MODEL_NAME ) >> Manufacturers_Model_Name;
    dset(dicom::TAG_PAT_NAME ) >> Patients_Name;
    dset(dicom::TAG_PAT_BIRTH_DATE ) >> Patients_Birth_Date;
    dset(dicom::TAG_PAT_SEX ) >> Patients_Sex;
    dset(dicom::TAG_PAT_AGE ) >> Patients_Age;
    dset(dicom::TAG_PAT_WEIGHT ) >> Patients_Weight;
    //dset(dicom::TAG_ADDITIONAL_PT_HISTORY ) >> Additional_Patient_History; brak typu
    dset(dicom::TAG_PAT_ID ) >> Patient_ID;

    dset(dicom::TAG_SOFTWARE_VERSION ) >> Software_Versions;
    //dset(dicom::TAG_VIEW_POSITION ) >> Patient_Position; brak typu
    dset(dicom::TAG_STUDY_INST_UID ) >> Study_Instance_UID; //brak typu
    dset(dicom::TAG_STUDY_ID ) >> Study_ID;
    dset(dicom::TAG_SERIES_NO ) >> Series_Number;
    dset(dicom::TAG_ACQUISITION_NO ) >> Acquisition_Number;
    //dset(dicom::TAG_PATIENT_ORIENTATION ) >> Patient_Orientation;
    //dset(dicom::TAG_IMAGE_POS  ) >> Image_Position_Patient; brak typu
    ///////////
    dset(dicom::TAG_IMAGE_ORIENTATION ) >> Image_Orientation_Patient;
    dset(dicom::TAG_SAMPLES_PER_PX ) >> Samples_per_Pixel;
    dset(dicom::TAG_PHOTOMETRIC ) >> Photometric_Interpretetion;
    dset(dicom::TAG_ROWS ) >> Rows;
    dset(dicom::TAG_COLUMNS ) >> Columns;
    dset(dicom::TAG_PIXEL_SPACING ) >> Pixel_Spacing;

    dset(dicom::TAG_PX_REPRESENT ) >> Pixel_Representation;
    //dset(dicom::TAG_SMALLEST_IMG_PX_VALUE ) >> Smallest_Image_Pixel_Value; brak typu
    //dset(dicom::TAG_LARGEST_IMG_PX_VALUE ) >> Largest_Image_Pixel_Value; brak typu
    dset(dicom::TAG_WINDOW_CENTER ) >> Window_Center;
    dset(dicom::TAG_WINDOW_WIDTH ) >> Window_Width;
    dset(dicom::TAG_RESCALE_INTERCEPT ) >> Rescale_Intercept;
    dset(dicom::TAG_RESCALE_SLOPE ) >> Rescale_Slope;
    //dset(dicom::TAG_RESCALE_TYPE ) >> Rescale_Type; brak typu

    dset(dicom::TAG_BITS_ALLOC ) >> Bits_Allocated;
    dset(dicom::TAG_BITS_STORED ) >> Bits_Stored;

    dset(dicom::TAG_HIGH_BIT ) >> High_Bit;
}

QImage DicomItem::toImage() const
{
        if (Samples_per_Pixel == 1)
        {
                QImage img(Columns, Rows, QImage::Format_Indexed8);
                img.setColorCount(256);
                for (int i = 0; i < 256; i++)
                {
                        img.setColor(i, QColor(i, i, i, 255).rgb());
                }
                UINT8 *image = img.bits();
                getImage(&image, iWindowMin, iWindowMax);
                return img;

        } else
        if (Samples_per_Pixel == 3)
        {
                QImage img(Columns, Rows, QImage::Format_RGB888);
                UINT8 *image = img.bits();
                getImage(&image);
                return img;
        } else
        {
                return QImage();
        }
}

QPixmap DicomItem::toPixmap() const
{
        return QPixmap::fromImage(toImage());
}

std::vector<int> DicomItem::min() const
{
        const std::vector<UINT16> *input;
        std::vector<UINT16> input16;

        if (iPixelData.vr() == dicom::VR_OW)
        {
                input = &(iPixelData.Get<std::vector<UINT16> >());
        } else
        if (iPixelData.vr() == dicom::VR_OB)
        {
                const std::vector<UINT8> &input8(iPixelData.Get<std::vector<UINT8 > >());
                for (std::vector<UINT8>::const_iterator it = input8.begin(); it != input8.end(); it++)
                {
                        input16.push_back(*it);
                }
                input = &input16;
        } else
        {
                return std::vector<int>();
        }

        std::vector<int> tmp(Samples_per_Pixel);
        for (int i = 0; i < Samples_per_Pixel; i++)
        {
                tmp.push_back(input->operator [](i));
        }

        std::vector<UINT16>::const_iterator pInput = input->begin();
        for (int count = Samples_per_Pixel * Columns * Rows, count2 = 0; count > 0; --count, ++count2)
        {
                int val = (*pInput) >> (1 + High_Bit - Bits_Stored);
                int &minVal(tmp[count2 % Samples_per_Pixel]);

                if (val < minVal)
                {
                        minVal = val;
                }

                pInput++;
        }
        return tmp;
}

std::vector<int> DicomItem::max() const
{
        const std::vector<UINT16> *input;
        std::vector<UINT16> input16;

        if (iPixelData.vr() == dicom::VR_OW)
        {
                input = &(iPixelData.Get<std::vector<UINT16> >());
        } else
        if (iPixelData.vr() == dicom::VR_OB)
        {
                const std::vector<UINT8> &input8(iPixelData.Get<std::vector<UINT8 > >());
                for (std::vector<UINT8>::const_iterator it = input8.begin(); it != input8.end(); it++)
                {
                        input16.push_back(*it);
                }
                input = &input16;
        } else
        {
                return std::vector<int>();
        }

        std::vector<int> tmp(Samples_per_Pixel);
        for (int i = 0; i < Samples_per_Pixel; i++)
        {
                tmp.push_back(input->operator[](i));
        }

        std::vector<UINT16>::const_iterator pInput = input->begin();
        for (int count = Samples_per_Pixel * Columns * Rows, count2 = 0; count > 0; --count, ++count2)
        {
                int val = (*pInput) >> (1 + High_Bit - Bits_Stored);
                int &maxVal(tmp[count2 % Samples_per_Pixel]);

                if (val > maxVal)
                {
                        maxVal = val;
                }

                pInput++;
        }
        return tmp;
}

void DicomItem::getImage(UINT8 **aImage, int aWindowMin, int aWindowMax) const
{
        if (!aImage) return;

        UINT8 *image;
        if (!*aImage)
        {
                *aImage = image = new UINT8[Samples_per_Pixel * Columns * Rows];
        } else
        {
                image = *aImage;
        }

        UINT8 *pImage = image;
        const std::vector<UINT16> *input;
        std::vector<UINT16> input16;

        if (iPixelData.vr() == dicom::VR_OW)
        {
                input = &(iPixelData.Get<std::vector<UINT16> >());
        } else
        if (iPixelData.vr() == dicom::VR_OB)
        {
                const std::vector<UINT8> &input8(iPixelData.Get<std::vector<UINT8 > >());
                for (std::vector<UINT8>::const_iterator it = input8.begin(); it != input8.end(); it++)
                {
                        input16.push_back(*it);
                }
                input = &input16;
        } else
        {
                return;
        }

        std::vector<UINT16>::const_iterator pInput = input->begin();
        for (int count = Samples_per_Pixel * Columns * Rows; count > 0; --count)
        {
                int val = (*pInput) >> (1 + High_Bit - Bits_Stored);
                if (Samples_per_Pixel == 1 && aWindowMin != aWindowMax)
                {
                        val = val < aWindowMin ? 0 : (val > aWindowMax ? 255 : (val - aWindowMin) * 255 / (aWindowMax - aWindowMin));
                }
                *pImage++ = val;
                pInput++;
        }
}

