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
    ui(new Ui::MainWindow),
    dicom_file(0)
{
    ui->setupUi(this);
    zvalue=1;
    QObject::connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(Open()));
    QObject::connect(ui->actionDefault,SIGNAL(triggered()),this,SLOT(PresDef()));
    QObject::connect(ui->actionSkull,SIGNAL(triggered()),this,SLOT(PresSkull()));
    QObject::connect(ui->actionLung,SIGNAL(triggered()),this,SLOT(PresLung()));
    QObject::connect(ui->actionAbdomen,SIGNAL(triggered()),this,SLOT(PresAbdomen()));
    QObject::connect(ui->actionBone,SIGNAL(triggered()),this,SLOT(PresBone()));
    QObject::connect(ui->actionSpine,SIGNAL(triggered()),this,SLOT(PresSpine()));
    QObject::connect(ui->actionZoom_50,SIGNAL(triggered()),this,SLOT(zoomChanged_p25()));
    QObject::connect(ui->actionZoom_51,SIGNAL(triggered()),this,SLOT(zoomChanged_m25()));
    QObject::connect(ui->actionZoom_100,SIGNAL(triggered()),this,SLOT(zoomChanged_100()));

    ui->graphicsView->setScene(new QGraphicsScene(this));
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete dicom_file;
}

void MainWindow::Open()
{
    QString fname = QFileDialog::getOpenFileName(this, tr("Open Dicom File"),"/home",tr("DICOM (*.dcm)"));

    if (fname != "")
    {

        dicom::DataSet dset;
        dicom::Read(fname.toStdString(), dset);
        delete dicom_file;

        dicom_file = new DicomItem(dset);

        /***************IMAGE DISPLAY***********************************/
        /****************START*******************************************/

        ui->graphicsView->scene()->clear();
        UINT16 winCenter;
        UINT16 winWidth;
        bool ok;
        std::vector<int> min(dicom_file->min());
        std::vector<int> max(dicom_file->max());
        dicom_file->setWindowMin(min[0]);
        dicom_file->setWindowMax(max[0]);
        ui->graphicsView->scene()->addPixmap(dicom_file->toPixmap());

        ui->graphicsView->setSceneRect(0, 0, dicom_file->fcolumns(), dicom_file->frows());

        /***************IMAGE DISPLAY***********************************/
        /****************START*******************************************/


        /***************TAGS DISPLAY***********************************/
        /****************START*******************************************/
        QTableWidgetItem *row = new QTableWidgetItem[88];

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
        SetTableRow(39, row, "Study Instance UID", QString::fromStdString(dicom_file->fst_ins_uid()));
        SetTableRow(40, row, "SOP Class UID", QString::fromStdString(dicom_file->fsop_cl_uid()));
        SetTableRow(41, row, "SOP Instance UID", QString::fromStdString(dicom_file->fsop_ins_uid()));

        /***************TAGS DISPLAY***********************************/
        /****************END************************************************/


        //DRZEWO
        /*QTreeWidgetItem *all_patients = new QTreeWidgetItem(ui->treeWidget);
        all_patients->setText(0, tr("All Patients"));

        QTreeWidgetItem *name = new QTreeWidgetItem(all_patients);
        name->setText(0, QString::number(dicom_file->fhight_bit(), 10)); */

        /*
        QTreeWidgetItem *modality = new QTreeWidgetItem(name);
        modality->setText(0, tr("modality"));

        QTreeWidgetItem *series_desc = new QTreeWidgetItem(modality);
        series_desc->setText(0, tr("series_desc"));
        */


        ui->lname->setText(QString("%1 ").arg(QString::fromStdString(dicom_file->fpat_name())));
        ui->lmod->setText(QString("%1 ").arg(QString::fromStdString(dicom_file->fmod())));
        ui->lseries->setText(QString("%1 ").arg(QString::fromStdString(dicom_file->fse_desc())));
        //ui->ldate->setText(QString("%1 ").arg((QDate::toString ( QString::fromStdString(dicom_file->fst_date()), "yyyy.MM.dd" ))));
        //QDate date=QDate::toString("20040301","yyyyMMdd");

    }

}

void MainWindow::zoomChanged_p25()
{
    if (dicom_file)
    {
        zvalue=zvalue+0.25;
        ui->graphicsView->setTransform(QTransform::fromScale(zvalue,zvalue));
    }
}

void MainWindow::zoomChanged_m25()
{
    if (dicom_file)
    {
        if(zvalue!=0)
        {
            zvalue=zvalue-0.25;
            ui->graphicsView->setTransform(QTransform::fromScale(zvalue,zvalue));
        }
    }
}

void MainWindow::zoomChanged_100()
{
    if (dicom_file)
    {
        zvalue=1;
        ui->graphicsView->setTransform(QTransform::fromScale(zvalue,zvalue));
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

void MainWindow::PresDef()
{
        if (dicom_file)
        {
            dicom_file->setWindowMin(939);
            dicom_file->setWindowMax(1227);
            ui->graphicsView->scene()->clear();
            ui->graphicsView->scene()->addPixmap(dicom_file->toPixmap());
        }
}

void MainWindow::PresAbdomen()
{
    if (dicom_file)
    {
        dicom_file->setWindowMin(826);
        dicom_file->setWindowMax(1291);
        ui->graphicsView->scene()->clear();
        ui->graphicsView->scene()->addPixmap(dicom_file->toPixmap());
    }
}

void MainWindow::PresBone()
{
    if (dicom_file)
    {
        dicom_file->setWindowMin(79);
        dicom_file->setWindowMax(2548);
        ui->graphicsView->scene()->clear();
        ui->graphicsView->scene()->addPixmap(dicom_file->toPixmap());
    }
}

void MainWindow::PresLung()
{
    if (dicom_file)
    {
        dicom_file->setWindowMin(0);
        dicom_file->setWindowMax(1414);
        ui->graphicsView->scene()->clear();
        ui->graphicsView->scene()->addPixmap(dicom_file->toPixmap());
    }
}


void MainWindow::PresSkull()
{
    if (dicom_file)
    {
        dicom_file->setWindowMin(1002);
        dicom_file->setWindowMax(1098);
        ui->graphicsView->scene()->clear();
        ui->graphicsView->scene()->addPixmap(dicom_file->toPixmap());
    }
}

void MainWindow::PresSpine()
{
    if (dicom_file)
    {
        dicom_file->setWindowMin(896);
        dicom_file->setWindowMax(1221);
        ui->graphicsView->scene()->clear();
        ui->graphicsView->scene()->addPixmap(dicom_file->toPixmap());
    }
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
