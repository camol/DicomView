#ifndef DICOMITEM_H
#define DICOMITEM_H

#include <dicomlib/dicomlib.hpp>
#include <QTreeWidgetItem>
#include <strings.h>
#include <QImage>
#include <QPixmap>


/**
* @page DicomItem Class DicomItem.
* Class witch provides keeps and provides vital date from DICOM files.
*/

class DicomItem
{

public:

    /**
    * Constructor for DicomItem Class.@n
    * During the creation of new DicomItem element it gathers the date from the original file
    * and stores them to variables of the class.
    * @param const dicom::DataSet &dset
    */

    DicomItem(const dicom::DataSet &dset);


public:

    /**
    * Method which defines a picture thanks to informations from DICOM tags stored in variables: Samples_per_Pixel, Columns, Rows
    * in class DicomItem.
    * @param UINT8
    * @param int
    * @param int
    * @return void
    */
        void getImage(UINT8 **aImage, int aWindowMin = 0, int aWindowMax = 0) const;


        /**
        * setWindowMin.
        * @param int
        * @return void
        */
        void setWindowMin(int aMin) { iWindowMin = aMin; }


        /**
        * setWindowMax.
        * @param int
        * @return void
        */
        void setWindowMax(int aMax) { iWindowMax = aMax; }

        /**
        * CurrentWindowMin.
        * @param void
        * @return int
        */
        int CurrentWindowMin() { return iWindowMin; }

        /**
        * CurrentWindowMax.
        * @param void
        * @return int
        */
        int CurrentWindowMax() { return iWindowMax; }

        /**
        * Method which creates and returns image information in object QImage
        * @param void
        * @return QImage
        */

        QImage toImage() const;



        /**
        * Method which translates QImage and returns a QPixmap object
        * @param void
        * @return QPixmap
        */

        QPixmap toPixmap() const;


        /**
        * Method setting the minimum of window level
        * @param void
        * @return std::vector<int>
        */

        std::vector<int> min() const;


        /**
        * Method setting the maximum of window level
        * @param void
        * @return std::vector<int>
        */

        std::vector<int> max() const;


    private:
            dicom::Value iPixelData;
            int iWindowMin;
            int iWindowMax;

public:
    std::string fadd_pat_hist() {return Add_Pat_History;}
    int fhight_bit() { return High_Bit; }
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


    std::string fse_ins_uid() {return Series_Inst_UID.str(); }
    std::string fst_ins_uid() { return Study_Instance_UID.str(); }
    std::string fsop_cl_uid() { return SOP_Class_UID.str(); }
    std::string fsop_ins_uid() { return SOP_Instance_UID.str(); }
    std::string fref_phys_name() { return Refering_Physician_Name; }
    std::string fchar_set() { return Character_Set; }
    std::string finst_name() { return Institution_Name; }
    std::string finst_adr() { return Institution_Address; }
    std::string fPPS_s_d() { return PPS_Start_Date; }
    std::string freq_phy() { return Request_Physician; }
    std::string freq_pro_desc() { return  Request_Procedure_Description; }
    std::string fPPS_ID() { return PPS_ID; }
    std::string fPPS_s_t() { return PPS_Start_Time; }
    std::string fPPS_desc() { return PPS_Description; }
    std::string fb_p_exe() { return Body_Part_Examined; }
    std::string fKVP() { return KVP; }
    std::string fprot_name() { return Protocol_Name; }
    std::string fb_p_thick() { return Body_Part_Thickness; }
    std::string fdis_sd() { return DistanceSD; }
    std::string fdis_sp() { return DistanceSP; }
    std::string fexp_tim() { return Exposure_Time; }
    std::string fx_ray_t() { return X_Ray_Tube; }
    std::string fexp() { return Exposure; }
    std::string ff_type() { return Filter_Type; }
    std::string ff_spot() { return Focal_Spot; }
    std::string fimg_no() { return Image_No; }
    std::string fimg_or() { return Image_Orientation; }
    std::string fc_v() { return Code_Value; }
    std::string fsps_p_name() {SPS_Perf_Name;}
    std::string fope_name() {Operators_Name;}
private:
    std::string Operators_Name;
    std::string SPS_Perf_Name;
    std::string Add_Pat_History;
    std::string Code_Value;
    std::string Image_Orientation;
    std::string Image_No;
    std::string Focal_Spot;
    std::string Filter_Type;
    std::string Exposure;
    std::string X_Ray_Tube;
    std::string DistanceSD;
    std::string DistanceSP;
    std::string Exposure_Time;
    std::string Img_Type;
    dicom::UID SOP_Class_UID;
    dicom::UID SOP_Instance_UID;
    std::string Study_Date;
    std::string Series_Date;
    std::string Acquisition_Date;

    std::string Study_Time;
    std::string Series_Time;
    std::string Acquisition_Time;
    std::string Content_Time;

    std::string Accession_Number;
    std::string Modality;
    std::string Manufacturer;
    std::string Institution_Name;
    std::string Institution_Address;
    dicom::UID Referenced_Study_Sequence;
    std::string Station_Name;
    std::string Study_Description;
    std::string Series_Description;

    std::string Character_Set;
    dicom::UID Series_Inst_UID;
    std::string Manufacturers_Model_Name;
    std::string Body_Part_Examined;
    std::string Body_Part_Thickness;
    std::string KVP;
    std::string Protocol_Name;
    std::string Request_Physician;
    std::string Request_Procedure_Description;
    std::string PPS_Start_Date;
    std::string PPS_Start_Time;
    std::string PPS_ID;
    std::string PPS_Description;




    std::string Patients_Name;
    std::string Patients_Birth_Date;
    std::string Patients_Sex;
    std::string Patients_Age;
    std::string Patients_Weight;

    std::string Patient_ID;

    std::string Software_Versions;
    std::string Refering_Physician_Name;
    std::string View_Position;
    dicom::UID Study_Instance_UID;
    std::string Series_Instance_UID;
    std::string Study_ID;
    std::string Series_Number;
    std::string Acquisition_Number;
    std::string Image_Position_Patient;

    UINT16 Samples_per_Pixel;
    std::string Photometric_Interpretetion;
    UINT16 Rows;
    UINT16 Columns;
    std::string Pixel_Spacing;
    UINT16 Bits_Allocated;
    UINT16 Bits_Stored;
    UINT16 High_Bit;
    UINT16 Pixel_Representation;
    std::string Window_Center;
    std::string Window_Width;
    std::string Rescale_Intercept;
    std::string Rescale_Slope;
    std::string Rescale_Type;
    std::string SPS_Description;


    public:

    /**
    * Method which checks if the given Tag exists in opened DICOM file
    * @param const dicom::DataSet
    * @param dicom::Tag
    * @param std::string
    * @return void
    */
    void TagCheck(const dicom::DataSet &dset, dicom::Tag tag, std::string &a);


    /**
    * Method which checks if the given Tag exists in opened DICOM file
    * @param const dicom::DataSet
    * @param dicom::Tag
    * @param std::UID
    * @return void
    */

    void TagCheck(const dicom::DataSet &dset, dicom::Tag tag, dicom::UID &a);


    /**
    * Method which checks if the given Tag exists in opened DICOM file
    * @param const dicom::DataSet
    * @param dicom::Tag
    * @param std::UID
    * @return void
    */

    void TagCheck(const dicom::DataSet &dset, dicom::Tag tag, UINT16 &a);


};

#endif // DICOMITEM_H
