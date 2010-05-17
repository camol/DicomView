#ifndef DICOMITEM_H
#define DICOMITEM_H

#include <dicomlib/dicomlib.hpp>
#include <QTreeWidgetItem>
#include <strings.h>


class DicomItem
{
public:
    DicomItem(const dicom::DataSet &dset);;
public:
    int fhight_bit() { return Hight_Bit; }
    int fbit_alloc() { return Bits_Allocated; }
    int fbit_stored() { return Bits_Stored; }
    int frows() { return Rows; }
    int fcolumns() { return Columns; }
    std::string fpix_spac() { return Pixel_Spacing; }
    int fsam_per_pix() { return Samples_per_Pixel; }
    std::string fphoto_inter() { return Photometric_Interpretetion; }
    int fpix_rep() { return Pixel_Representation; }
    std::string fw_w() { return Window_Width; }
    std::string fw_c() { return Window_Center; }
    std::string fr_i() { return Rescale_Intercept; }
    std::string fr_s() { return Rescale_Slope; }
    //std::string fr_t() { return Rescale_Type; }

    std::string fimg_pos() { return Image_Position_Patient; }
    std::string fimg_type() { return Img_Type; }
    std::string fst_date() { return Study_Date; }
    std::string fse_date() { return Series_Date; }
    std::string facq_date() { return Acquisition_Date; }
    std::string fst_time() { return Study_Time; }
    std::string fse_time() { return Series_Time; }
    std::string facq_time() { return Acquisition_Time; }
    std::string fcon_time() { return Content_Time; }
    std::string facc_nr() { return Accession_Number; }
    std::string fmod() { return Modality; }
    std::string fman() { return Manufacturer; }
    std::string fst_desc() { return Study_Description; }
    std::string fstat_name() { return Station_Name; }
    std::string fse_desc() { return Series_Description; }
    std::string fman_mod_name() { return Manufacturers_Model_Name; }

    std::string fpat_name() {return Patients_Name;}
    std::string fpat_birth() {return Patients_Birth_Date;}
    std::string fpat_sex() {return Patients_Sex;}
    std::string fpat_age() {return Patients_Age;}
    std::string fpat_wei() {return Patients_Weight;}
    std::string fpat_id() {return Patient_ID;}

    std::string fsoft_ver() {return Software_Versions;}
    std::string fst_id() {return Study_ID;}
    std::string fse_nr() {return Series_Number;}
    std::string facq_nr() { return Acquisition_Number; }
    std::string fimg_pos_pat() { return Image_Position_Patient; }
    std::string fimg_or_pat() { return Image_Orientation_Patient; }





private:
    std::string Img_Type;
    std::string SOP_Class_UID;
    double SOP_Instance_UID;
    std::string Study_Date;
    std::string Series_Date;
    std::string Acquisition_Date;
    //UINT16 Content_Date; ????????????????? nie wiem ktory to TAG
    std::string Study_Time;
    std::string Series_Time;
    std::string Acquisition_Time;
    std::string Content_Time;

    std::string Accession_Number;
    std::string Modality;
    std::string Manufacturer;
    UINT16 Institution_Name;

    std::string Station_Name;
    std::string Study_Description;
    std::string Series_Description;
    std::string Performing_Physicians_Name;
    UINT16 Operators_Name;
    std::string Manufacturers_Model_Name;

    std::string Patients_Name;
    std::string Patients_Birth_Date;
    std::string Patients_Sex;
    std::string Patients_Age;
    std::string Patients_Weight;
    UINT16 Additional_Patient_History;
    std::string Patient_ID;

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

    std::string Software_Versions;
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


    std::string Patient_Position;
    UINT16 Study_Instance_UID;
    std::string Series_Instance_UID;
    std::string Study_ID;
    std::string Series_Number;
    std::string Acquisition_Number;
    //UINT16 Instance_Number; nie wiem jaki tag
    //std::string Patient_Orientation; brak typu
    std::string Image_Position_Patient;
    std::string Image_Orientation_Patient;//

    //UINT16 Image_Orientation_Patient;
    //UINT16 Frame_of_Reference_UID;
    //UINT16 Images_in_Acquisition;
    //UINT16 Position_Reference_Indicator;
    //UINT16 Slice_Location;

    UINT16 Samples_per_Pixel;//
    std::string Photometric_Interpretetion;//
    UINT16 Rows;//
    UINT16 Columns;//
    std::string Pixel_Spacing;//
    UINT16 Bits_Allocated;//
    UINT16 Bits_Stored;//
    UINT16 Hight_Bit;//
    UINT16 Pixel_Representation;//
    //std::string Smallest_Image_Pixel_Value;//
    //std::string Largest_Image_Pixel_Value;//
    //UINT16 Pixel_Padding_Value; nie wiem który to tag
    std::string Window_Center;//
    std::string Window_Width;//
    std::string Rescale_Intercept;//
    std::string Rescale_Slope;//
    std::string Rescale_Type;//

};

#endif // DICOMITEM_H
