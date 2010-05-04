#ifndef DICOMITEM_H
#define DICOMITEM_H

#include <dicomlib/dicomlib.hpp>
#include <QTreeWidgetItem>


class DicomItem : public QTreeWidgetItem
{
public:
    DicomItem(const dicom::DataSet &dset);;
public:
    int fpat_name() { return Patients_Name; }
private:
    UINT16 Img_Type;
    UINT16 SOP_Class_UID;
    UINT16 SOP_Instance_UID;
    UINT16 Study_Date;
    UINT16 Series_Date;
    UINT16 Acquisition_Date;
    //UINT16 Content_Date; ????????????????? nie wiem ktory to TAG
    UINT16 Study_Time;
    UINT16 Series_Time;
    UINT16 Acquisition_Time;
    //UINT16 Content_Time;    ????tez nie wiem

    //UINT16 Accession_Number;  nie wiem
    UINT16 Modality;
    UINT16 Manufactor;
    UINT16 Institution_Name;

    UINT16 Station_Name;
    UINT16 Study_Description;
    UINT16 Series_Description;
    UINT16 Performing_Physicians_Name;
    UINT16 Operators_Name;
    UINT16 Manufacturers_Model_Name;

    UINT16 Patients_Name;
    UINT16 Patients_ID;
    UINT16 Patients_Birth_Date;
    UINT16 Patients_Sex;
    UINT16 Patients_Age;
    UINT16 Patients_Weight;
    UINT16 Additional_Patient_History;

    //UINT16 Scanning_Sequence;   niewiem
    //UINT16 Sequence_Variant; niewiem
    //UINT16 Scan_Options; niewiem
    //UINT16 MR_Acquisition_Type; niewiem
    //UINT16 Sequence_Name;niewiem
    //UINT16 Slice_Thickeness;niewiem
    //UINT16 Repetition_Time;niewiem
    //UINT16 Echo_Time;
    //UINT16 Number_of_Averages;
    //UINT16 Imaging_Frequency;
    //UINT16 Echo_Numbers;
    //UINT16 Magnetic_Field_Strength;
    //UINT16 Spacing_Between_Slices;
    //UINT16 Number_of_Phase_Encoding_Steps;
    //UINT16 Echo_Train_Length;
    UINT16 Pixel_Bandwidth;
    UINT16 Software_Versions;
    //UINT16 Protocol_Name;
    //UINT16 Heart_Rate;
    //UINT16 Cardiac_Number_of_Images;
    //UINT16 Trigger_Window;
    //UINT16 Reconstruction_Diameter;
    //UINT16 Receive_Coil_Name;
    //UINT16 Acquisation_Matrix;
    //UINT16 In_plane_Phase_Encoding_Direction;
    //UINT16 Flip_Angle;
    //UINT16 SAR;

    UINT16 Patient_Position;
    UINT16 Study_Instance_UID;
    UINT16 Series_Instance_UID;
    UINT16 Study_ID;
    UINT16 Series_Number;
    UINT16 Acquisition_Number;
    //UINT16 Instance_Number;
    UINT16 Patient_Orientation;
    UINT16 Image_Position;
    UINT16 Image_Position_Patient;
    UINT16 Image_Orientation;
    //UINT16 Image_Orientation_Patient;
    //UINT16 Frame_of_Reference_UID;
    //UINT16 Images_in_Acquisition;
    //UINT16 Position_Reference_Indicator;
    //UINT16 Slice_Location;

    UINT16 Samples_per_Pixel;
    UINT16 Photometric_Interpretetion;
    UINT16 Rows;
    UINT16 Columns;
    UINT16 Pixel_Spacing;
    UINT16 Bits_Allocated;
    UINT16 Bits_Stored;
    UINT16 Hight_Bit;
    UINT16 Pixel_Representation;
    UINT16 Smallest_Image_Pixel_Value;
    UINT16 Largest_Image_Pixel_Value;
    //UINT16 Pixel_Padding_Value;
    UINT16 Window_Center;
    UINT16 Window_Width;
    UINT16 Rescale_Intercept;
    UINT16 Rescale_Slope;
    UINT16 Rescale_Type;

};

#endif // DICOMITEM_H
