#include "dicomitem.h"



DicomItem::DicomItem(const dicom::DataSet &dset):
        iPixelData(dset(dicom::TAG_PIXEL_DATA))
{
    TagCheck(dset, dicom::TAG_SERIES_INST_UID,Series_Inst_UID);
    TagCheck(dset, dicom::TAG_IMAGE_TYPE,Img_Type);
    TagCheck(dset, dicom::TAG_SOP_CLASS_UID,SOP_Class_UID);
    TagCheck(dset, dicom::TAG_SOP_INST_UID,SOP_Instance_UID);
    TagCheck(dset, dicom::TAG_STUDY_DATE,Study_Date);
    TagCheck(dset, dicom::TAG_SERIES_DATE,Series_Date);
    TagCheck(dset, dicom::TAG_ACQUISITION_DATE,Acquisition_Date);
    TagCheck(dset, dicom::TAG_STUDY_TIME,Study_Time);
    TagCheck(dset, dicom::TAG_SERIES_TIME,Series_Time);
    TagCheck(dset, dicom::TAG_ACQUISITION_TIME,Acquisition_Time);
    TagCheck(dset, dicom::TAG_ACQUISITION_TIME,Content_Time);
    TagCheck(dset, dicom::TAG_MODALITY,Modality);
    TagCheck(dset, dicom::TAG_MANUFACTOR,Manufacturer);
    TagCheck(dset, dicom::TAG_INSTITUT_NAME,Institution_Name);
    TagCheck(dset, dicom::TAG_INSTITUT_ADDRESS,Institution_Address);
    TagCheck(dset, dicom::TAG_STUDY_DESC,Study_Description);
    TagCheck(dset, dicom::TAG_STATION_NAME,Station_Name);
    TagCheck(dset, dicom::TAG_SERIES_DESC,Series_Description);
    TagCheck(dset, dicom::TAG_REF_PHYS_NAME,Refering_Physician_Name);
    TagCheck(dset, dicom::TAG_MANFAC_MODEL_NAME,Manufacturers_Model_Name);
    TagCheck(dset, dicom::TAG_PAT_NAME,Patients_Name);
    TagCheck(dset, dicom::TAG_PAT_BIRTH_DATE,Patients_Birth_Date);
    TagCheck(dset, dicom::TAG_PAT_SEX,Patients_Sex);
    TagCheck(dset, dicom::TAG_PAT_AGE,Patients_Age);
    TagCheck(dset, dicom::TAG_PAT_WEIGHT,Patients_Weight);
    TagCheck(dset, dicom::TAG_PAT_SEX,Patients_Sex);
    TagCheck(dset, dicom::TAG_PAT_SEX,Patients_Sex);
    TagCheck(dset, dicom::TAG_ADDITIONAL_PT_HISTORY,Add_Pat_History);//
    TagCheck(dset, dicom::TAG_SPS_PERF_PHYS_NAME,SPS_Perf_Name);//
    TagCheck(dset, dicom::TAG_OPERATOR_NAME,Operators_Name);//
    TagCheck(dset, dicom::TAG_PAT_ID,Patient_ID);
    TagCheck(dset, dicom::TAG_SOFTWARE_VERSION,Software_Versions);
    TagCheck(dset, dicom::TAG_VIEW_POSITION,View_Position);//
    TagCheck(dset, dicom::TAG_STUDY_INST_UID,Study_Instance_UID);
    TagCheck(dset, dicom::TAG_STUDY_ID,Study_ID);
    TagCheck(dset, dicom::TAG_SERIES_NO,Series_Number);
    TagCheck(dset, dicom::TAG_ACQUISITION_NO,Acquisition_Number);
    TagCheck(dset, dicom::TAG_IMAGE_POS,Image_Position_Patient);//
    TagCheck(dset, dicom::TAG_SAMPLES_PER_PX,Samples_per_Pixel);
    TagCheck(dset, dicom::TAG_PHOTOMETRIC,Photometric_Interpretetion);
    TagCheck(dset, dicom::TAG_ROWS,Rows);
    TagCheck(dset, dicom::TAG_COLUMNS,Columns);
    TagCheck(dset, dicom::TAG_PIXEL_SPACING,Pixel_Spacing);
    TagCheck(dset, dicom::TAG_PX_REPRESENT,Pixel_Representation);
    TagCheck(dset, dicom::TAG_WINDOW_CENTER,Window_Center);
    TagCheck(dset, dicom::TAG_WINDOW_WIDTH,Window_Width);
    TagCheck(dset, dicom::TAG_RESCALE_INTERCEPT,Rescale_Intercept);
    TagCheck(dset, dicom::TAG_RESCALE_SLOPE,Rescale_Intercept);
    TagCheck(dset, dicom::TAG_RESCALE_TYPE,Rescale_Type);//
    TagCheck(dset, dicom::TAG_BITS_ALLOC,Bits_Allocated);
    TagCheck(dset, dicom::TAG_BITS_STORED,Bits_Stored);
    TagCheck(dset, dicom::TAG_HIGH_BIT,High_Bit);
    TagCheck(dset, dicom::TAG_CHAR_SET,Character_Set);
    TagCheck(dset, dicom::TAG_BODY_PART_EXAMINED,Body_Part_Examined);
    TagCheck(dset, dicom::TAG_BODY_PART_THICKNESS,Body_Part_Thickness);
    TagCheck(dset, dicom::TAG_KVP,KVP);
    TagCheck(dset, dicom::TAG_PROT_NAME,Protocol_Name);
    TagCheck(dset, dicom::TAG_DIST_SOURCE_DETECTOR,DistanceSD);
    TagCheck(dset, dicom::TAG_DIST_SOURCE_PATIENT,DistanceSP);
    TagCheck(dset, dicom::TAG_REQ_PHYS,Request_Physician);
    TagCheck(dset, dicom::TAG_REQ_PROC_DESC,Request_Procedure_Description);
    TagCheck(dset, dicom::TAG_CODE_VALUE,Code_Value);
    TagCheck(dset, dicom::TAG_PPS_START_DATE,PPS_Start_Date);
    TagCheck(dset, dicom::TAG_PPS_START_TIME,PPS_Start_Time);
    TagCheck(dset, dicom::TAG_PPS_ID,PPS_ID);
    TagCheck(dset, dicom::TAG_PPS_DESC,PPS_Description);
    TagCheck(dset, dicom::TAG_EXPOSURE_TIME,Exposure_Time);
    TagCheck(dset, dicom::TAG_XRAYTUBE_CURRENT,X_Ray_Tube);
    TagCheck(dset, dicom::TAG_EXPOSURE_MAS,Exposure);
    TagCheck(dset, dicom::TAG_FILTER_TYPE,Filter_Type);
    TagCheck(dset, dicom::TAG_FOCAL_SPOT,Focal_Spot);
    TagCheck(dset, dicom::TAG_IMAGE_NO,Image_No);
    TagCheck(dset, dicom::TAG_IMAGE_ORIENTATION,Image_Orientation);
    TagCheck(dset, dicom::TAG_SPS_DESC,SPS_Description);//


}

/**
* DicomItem Class DicomItem.
*/
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

void DicomItem::TagCheck(const dicom::DataSet &dset, dicom::Tag tag, std::string &a)
{
    if(dset.exists(tag))
    {
        dset(tag) >> a;
    }
    else
    {
        a="";
    }
}

void DicomItem::TagCheck(const dicom::DataSet &dset, dicom::Tag tag, dicom::UID &a)
{
    if(dset.exists(tag))
    {
        dset(tag) >> a;
    }
    else
    {
        a=dicom::UID::UID("");
    }
}

void DicomItem::TagCheck(const dicom::DataSet &dset, dicom::Tag tag, UINT16 &a)
{
    if(dset.exists(tag))
    {
        dset(tag) >> a;
    }
    else
    {
        a=0;
    }
}


