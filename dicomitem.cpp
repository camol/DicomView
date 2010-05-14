#include "dicomitem.h"

DicomItem::DicomItem(const dicom::DataSet &dset)
{
    //dset(dicom::TAG_IMAGE_TYPE) >> Img_Type;
    //dset(dicom::TAG_SOP_CLASS_UID) >> SOP_Class_UID;
    //dset(dicom::TAG_SOP_INST_UID ) >> SOP_Instance_UID;
    //dset(dicom::TAG_STUDY_DATE ) >> Study_Date;
    //dset(dicom::TAG_SERIES_DATE ) >> Series_Date;
    //dset(dicom::TAG_ACQUISITION_DATE ) >> Acquisition_Date;
    //dset(dicom::TAG_SOP_INST_UID ) >> Content_Date; nie wiem ktory to TAG
    //dset(dicom::TAG_STUDY_TIME ) >> Study_Time;
    //dset(dicom::TAG_SERIES_TIME ) >> Series_Time;
    //dset(dicom::TAG_ACQUISITION_TIME ) >> Acquisition_Time;
    //dset(dicom::TAG_SERIES_TIME ) >> Content_Time;  tez niewiem
    //dset(dicom::TAG_SERIES_TIME ) >> Accession_Number; nie wiem
    //dset(dicom::TAG_MODALITY  ) >> Modality;
    //dset(dicom::TAG_MANUFACTOR ) >> Manufactor;
    /*dset(dicom::TAG_INSTITUT_DEPT_NAME ) >> Institution_Name;
    dset(dicom::TAG_STUDY_DESC ) >> Study_Description;
    dset(dicom::TAG_STATION_NAME ) >> Station_Name;
    dset(dicom::TAG_SERIES_DESC ) >> Series_Description;
    dset(dicom::TAG_PERF_PHYS_NAME ) >> Performing_Physicians_Name;
    dset(dicom::TAG_OPERATOR_NAME ) >> Operators_Name;
    dset(dicom::TAG_MANFAC_MODEL_NAME ) >> Manufacturers_Model_Name; */
    dset(dicom::TAG_PAT_NAME ) >> Patients_Name;
    //dset(dicom::TAG_PAT_BIRTH_DATE ) >> Patients_Birth_Date;
    //dset(dicom::TAG_PAT_SEX ) >> Patients_Sex;
    //dset(dicom::TAG_PAT_AGE ) >> Patients_Age;
    //dset(dicom::TAG_PAT_WEIGHT ) >> Patients_Weight;
    //dset(dicom::TAG_ADDITIONAL_PT_HISTORY ) >> Additional_Patient_History;
    //dset(dicom::TAG_PAT_ID ) >> Scanning_Sequence; niewiem
    //dset(dicom::TAG_PIXEL_SPACING ) >> Pixel_Bandwidth;
    //dset(dicom::TAG_SOFTWARE_VERSION ) >> Software_Versions;
    //dset(dicom::TAG_VIEW_POSITION ) >> Patient_Position;
    //dset(dicom::TAG_STUDY_INST_UID ) >> Study_Instance_UID;
    //dset(dicom::TAG_STUDY_ID ) >> Study_ID;
    //dset(dicom::TAG_SERIES_NO ) >> Series_Number;
    //dset(dicom::TAG_ACQUISITION_NO ) >> Acquisition_Number;
    //dset(dicom::TAG_PATIENT_ORIENTATION ) >> Patient_Orientation;
    //dset(dicom::TAG_IMAGE_POS  ) >> Image_Position;
    dset(dicom::TAG_IMAGE_ORIENTATION ) >> Image_Position_Patient;
    dset(dicom::TAG_SAMPLES_PER_PX ) >> Samples_per_Pixel;
    dset(dicom::TAG_PHOTOMETRIC ) >> Photometric_Interpretetion;
    dset(dicom::TAG_ROWS ) >> Rows;
    dset(dicom::TAG_COLUMNS ) >> Columns;
    dset(dicom::TAG_PIXEL_SPACING ) >> Pixel_Spacing;
    dset(dicom::TAG_BITS_ALLOC ) >> Bits_Allocated;
    dset(dicom::TAG_BITS_STORED ) >> Bits_Stored;

    dset(dicom::TAG_HIGH_BIT ) >> Hight_Bit;
    dset(dicom::TAG_PX_REPRESENT ) >> Pixel_Representation;
    dset(dicom::TAG_SMALLEST_IMG_PX_VALUE ) >> Smallest_Image_Pixel_Value;
    dset(dicom::TAG_LARGEST_IMG_PX_VALUE ) >> Largest_Image_Pixel_Value;
    dset(dicom::TAG_WINDOW_CENTER ) >> Window_Center;
    dset(dicom::TAG_WINDOW_WIDTH ) >> Window_Width;
    dset(dicom::TAG_RESCALE_INTERCEPT ) >> Rescale_Intercept;
    dset(dicom::TAG_RESCALE_SLOPE ) >> Rescale_Slope;
    dset(dicom::TAG_RESCALE_TYPE ) >> Rescale_Type;
}
