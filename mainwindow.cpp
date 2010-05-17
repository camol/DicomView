#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QStringList>
#include <QList>
#include <QTreeWidget>
#include "dicomitem.h"
#include <dicomlib/dicomlib.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(Open()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Open()
{
    QString fname = QFileDialog::getOpenFileName(this, tr("Open Dicom File"),"/home",tr("DICOM (*.dcm)"));

    if (fname != "")
    {

        dicom::DataSet dset;
        dicom::Read(fname.toStdString(), dset);

        DicomItem *dicom_file = new DicomItem(dset);


        QTreeWidgetItem *all_patients = new QTreeWidgetItem(ui->treeWidget);
        all_patients->setText(0, tr("All Patients"));

        QTreeWidgetItem *name = new QTreeWidgetItem(all_patients);
        name->setText(0, QString::number(dicom_file->fhight_bit(), 10));


        /***************TAGS DISPLAY***********************************/
        /****************START*******************************************/
        QTableWidgetItem *row = new QTableWidgetItem[80];

        SetTableRow(0, row, "Image Type", QString::fromStdString(dicom_file->fimg_type()));
        SetTableRow(1, row, "Study Date", QString::fromStdString(dicom_file->fst_date()));
        SetTableRow(2, row, "Series Date", QString::fromStdString(dicom_file->fse_date()));
        SetTableRow(3, row, "Acquisition Date", QString::fromStdString(dicom_file->facq_date()));
        SetTableRow(4, row, "Study Time", QString::fromStdString(dicom_file->fst_time()));
        SetTableRow(5, row, "Series Time", QString::fromStdString(dicom_file->fse_time()));
        SetTableRow(6, row, "Acquisition Time", QString::fromStdString(dicom_file->facq_time()));
        SetTableRow(7, row, "Content Time", QString::fromStdString(dicom_file->fcon_time()));
        SetTableRow(8, row, "Accession Number", QString::fromStdString(dicom_file->facc_nr()));
        SetTableRow(9, row, "Modality", QString::fromStdString(dicom_file->fmod()));
        SetTableRow(10, row, "Manufacturer", QString::fromStdString(dicom_file->fman()));
        SetTableRow(11, row, "Study Description", QString::fromStdString(dicom_file->fst_desc()));\
        SetTableRow(12, row, "Station Name", QString::fromStdString(dicom_file->fstat_name()));
        SetTableRow(13, row, "Series Description", QString::fromStdString(dicom_file->fse_desc()));
        SetTableRow(14, row, "Manufacturer's Model Name", QString::fromStdString(dicom_file->fman_mod_name()));
        SetTableRow(15, row, "Patient's Name", QString::fromStdString(dicom_file->fpat_name()));
        SetTableRow(16, row, "Patient's Birth Date", QString::fromStdString(dicom_file->fpat_birth()));
        SetTableRow(17, row, "Patient's Sex", QString::fromStdString(dicom_file->fpat_sex()));
        SetTableRow(18, row, "Patient's Age", QString::fromStdString(dicom_file->fpat_age()));
        SetTableRow(19, row, "Patient's Weight", QString::fromStdString(dicom_file->fpat_wei()));
        SetTableRow(20, row, "Patient's ID", QString::fromStdString(dicom_file->fpat_id()));
        SetTableRow(21, row, "Software Version(s)", QString::fromStdString(dicom_file->fsoft_ver()));
        SetTableRow(22, row, "Study ID", QString::fromStdString(dicom_file->fst_id()));
        SetTableRow(23, row, "Series Number", QString::fromStdString(dicom_file->fse_nr()));
        SetTableRow(24, row, "Acquisition Number", QString::fromStdString(dicom_file->facq_nr()));
        SetTableRow(25, row, "Image Orientation (Patient)", QString::fromStdString(dicom_file->fimg_or_pat()));
        SetTableRow(26, row, "Samples per Pixel", QString::number(dicom_file->fsam_per_pix(), 10));
        SetTableRow(27, row, "Photometric Interpretetion", QString::fromStdString(dicom_file->fphoto_inter()));
        SetTableRow(28, row, "Rows", QString::number(dicom_file->frows(), 10));
        SetTableRow(29, row, "Columns", QString::number(dicom_file->fcolumns(), 10));
        SetTableRow(30, row, "Pixel Spacing", QString::fromStdString(dicom_file->fpix_spac()));
        SetTableRow(31, row, "Pixel Representation", QString::number(dicom_file->fpix_rep(), 10));
        SetTableRow(32, row, "Window Center", QString::fromStdString(dicom_file->fw_c()));
        SetTableRow(33, row, "Window Width", QString::fromStdString(dicom_file->fw_w()));
        SetTableRow(34, row, "Rescale Intercept", QString::fromStdString(dicom_file->fr_i()));
        SetTableRow(35, row, "Rescale Slope", QString::fromStdString(dicom_file->fr_s()));
        SetTableRow(36, row, "Bits Allocated", QString::number(dicom_file->fbit_alloc(), 10));
        SetTableRow(37, row, "Bits Stored", QString::number(dicom_file->fbit_stored(), 10));
        SetTableRow(38, row, "High Bit", QString::number(dicom_file->fhight_bit(), 10));


        /***************TAGS DISPLAY***********************************/
        /****************END************************************************/

/*
        QTreeWidgetItem *modality = new QTreeWidgetItem(name);
        modality->setText(0, tr("modality"));

        QTreeWidgetItem *series_desc = new QTreeWidgetItem(modality);
        series_desc->setText(0, tr("series_desc"));
        */




    }

}

void MainWindow::SetTableRow(int row_nr, QTableWidgetItem row[], QString name, QString value)
{
    ui->tableWidget->insertRow(row_nr);
    row[2*row_nr].setText(name);
    ui->tableWidget->setItem(row_nr, 0, &row[2*row_nr]);

    row[2*row_nr+1].setText(value);
    ui->tableWidget->setItem(row_nr, 1, &row[2*row_nr+1]);

    return ;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
