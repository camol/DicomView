#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QStringList>
#include <QList>
#include <QTreeWidget>

#include "MyGraphicsView.h"
#include "dicomitem.h"
#include <dicomlib/dicomlib.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dicom_file(0)
{
    ui->setupUi(this);

    dragVal = true;
    windowVal = false;
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
    QObject::connect(ui->actionRotate_Right,SIGNAL(triggered()),this,SLOT(rotateRight()));
    QObject::connect(ui->actionRotate_Left,SIGNAL(triggered()),this,SLOT(rotateLeft()));
    QObject::connect(ui->actionDrag,SIGNAL(triggered()),this,SLOT(setDrag()));
    QObject::connect(ui->actionManual_Windowing,SIGNAL(triggered()),this,SLOT(setWindowing()));
    QObject::connect(ui->actionCopy_to_Clipboard,SIGNAL(triggered()),this,SLOT(copyClip()));

    ui->graphicsView->setScene(new QGraphicsScene(this));
    ui->graphicsView->setDragMode(MyGraphicsView::ScrollHandDrag);

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
        QTableWidgetItem *row = new QTableWidgetItem[300];

        SetTableRow(0, row, "", "**********Group**********","0008");
        SetTableRow(1, row, "Character Set", QString::fromStdString(dicom_file->fchar_set()),"0008:0005");
        SetTableRow(2, row, "Image Type", QString::fromStdString(dicom_file->fimg_type()),"0008:0008");
        SetTableRow(3, row, "SOP Class UID", QString::fromStdString(dicom_file->fsop_cl_uid()),"0008:0016");
        SetTableRow(4, row, "Study Date", QString::fromStdString(dicom_file->fst_date()),"0008:0020");
        SetTableRow(5, row, "Series Date", QString::fromStdString(dicom_file->fse_date()),"0008:0021");
        SetTableRow(6, row, "Acquisition Date", QString::fromStdString(dicom_file->facq_date()),"0008:0022");
        SetTableRow(7, row, "Study Time", QString::fromStdString(dicom_file->fst_time()),"0008:0030");
        SetTableRow(8, row, "Series Time", QString::fromStdString(dicom_file->fse_time()),"0008:0031");
        SetTableRow(9, row, "Acquisition Time", QString::fromStdString(dicom_file->facq_time()),"0008:0032");
        SetTableRow(10, row, "Content Time", QString::fromStdString(dicom_file->fcon_time()),"0008:0033");
        SetTableRow(11, row, "Accession Number", QString::fromStdString(dicom_file->facc_nr()),"0008:0050");
        SetTableRow(12, row, "Modality", QString::fromStdString(dicom_file->fmod()),"0008:0060");
        SetTableRow(13, row, "Manufacturer", QString::fromStdString(dicom_file->fman()),"0008:0070");
        SetTableRow(14, row, "Institution Name", QString::fromStdString(dicom_file->finst_name()),"0008:0080");
        SetTableRow(15, row, "Institution Address", QString::fromStdString(dicom_file->finst_adr()),"0008:0081");
        SetTableRow(16, row, "Refering Physician Name", QString::fromStdString(dicom_file->fref_phys_name()),"0008:0090");
        SetTableRow(17, row, "Station Name", QString::fromStdString(dicom_file->fstat_name()),"0008:1010");
        SetTableRow(18, row, "Study Description", QString::fromStdString(dicom_file->fst_desc()),"0008:1030");
        SetTableRow(19, row, "Series Description", QString::fromStdString(dicom_file->fse_desc()),"0008:103E");
        SetTableRow(20, row, "Manufacturer's Model Name", QString::fromStdString(dicom_file->fman_mod_name()),"0008:1090");
        SetTableRow(21, row, "Code Value", QString::fromStdString(dicom_file->fc_v()),"0008:0100");
        SetTableRow(22, row, "SOP Instance UID", QString::fromStdString(dicom_file->fsop_ins_uid()),"0008:0018");

        SetTableRow(23, row, "", "**********Group**********","0010");
        SetTableRow(24, row, "Patient's Name", QString::fromStdString(dicom_file->fpat_name()),"0010:0010");
        SetTableRow(25, row, "Patient's ID", QString::fromStdString(dicom_file->fpat_id()),"0010:0020");
        SetTableRow(26, row, "Patient's Birth Date", QString::fromStdString(dicom_file->fpat_birth()),"0010:0030");
        SetTableRow(27, row, "Patient's Sex", QString::fromStdString(dicom_file->fpat_sex()),"0010:0040");
        SetTableRow(28, row, "Patient's Age", QString::fromStdString(dicom_file->fpat_age()),"0010:1010");
        SetTableRow(29, row, "Patient's Weight", QString::fromStdString(dicom_file->fpat_wei()),"0010:1030");

        SetTableRow(30, row, "", "**********Group**********","0018");
        SetTableRow(31, row, "Body Part Examined", QString::fromStdString(dicom_file->fb_p_exe()),"0018:0015");
        SetTableRow(32, row, "Body Part Thickeness", QString::fromStdString(dicom_file->fb_p_thick()),"0018:11A0");
        SetTableRow(33, row, "KVP", QString::fromStdString(dicom_file->fKVP()),"0018:0060");
        SetTableRow(34, row, "Software Version(s)", QString::fromStdString(dicom_file->fsoft_ver()),"0018:1020");
        SetTableRow(35, row, "Protocol Name", QString::fromStdString(dicom_file->fprot_name()),"0018:1030");
        SetTableRow(36, row, "Distance Source Detector", QString::fromStdString(dicom_file->fdis_sd()),"0018:1110");
        SetTableRow(37, row, "Distance Source Patient", QString::fromStdString(dicom_file->fdis_sp()),"0018:1111");
        SetTableRow(38, row, "Exposure Time", QString::fromStdString(dicom_file->fexp_tim()),"0018:1150");
        SetTableRow(39, row, "X Ray Tube Current", QString::fromStdString(dicom_file->fx_ray_t()),"0018:1151");
        SetTableRow(40, row, "Exposure", QString::fromStdString(dicom_file->fexp()),"0018:1152");
        SetTableRow(41, row, "Filter Type", QString::fromStdString(dicom_file->ff_type()),"0018:1160");
        SetTableRow(42, row, "Focal Spot", QString::fromStdString(dicom_file->ff_spot()),"0018:1190");


        SetTableRow(43, row, "", "**********Group**********","0020");
        SetTableRow(44, row, "Study Instance UID", QString::fromStdString(dicom_file->fst_ins_uid()),"0020:000D");
        SetTableRow(45, row, "Series Instance UID", QString::fromStdString(dicom_file->fse_ins_uid()),"0020:000E");
        SetTableRow(46, row, "Study ID", QString::fromStdString(dicom_file->fst_id()),"0020:0010");
        SetTableRow(47, row, "Series Number", QString::fromStdString(dicom_file->fse_nr()),"0020:0011");
        SetTableRow(48, row, "Acquisition Number", QString::fromStdString(dicom_file->facq_nr()),"0020:0012");
        SetTableRow(49, row, "Image No", QString::fromStdString(dicom_file->fimg_no()),"0020:0013");
        SetTableRow(50, row, "Image Orientation", QString::fromStdString(dicom_file->fimg_or()),"0020:0037");


        SetTableRow(51, row, "", "**********Group**********","0028");
        SetTableRow(52, row, "Samples per Pixel", QString::number(dicom_file->fsam_per_pix(), 10),"0028:0002");
        SetTableRow(53, row, "Photometric Interpretetion", QString::fromStdString(dicom_file->fphoto_inter()),"0028:0004");
        SetTableRow(54, row, "Rows", QString::number(dicom_file->frows(), 10),"0028:0010");
        SetTableRow(55, row, "Columns", QString::number(dicom_file->fcolumns(), 10),"0028:0011");
        SetTableRow(56, row, "Pixel Spacing", QString::fromStdString(dicom_file->fpix_spac()),"0028:0030");
        SetTableRow(57, row, "Bits Allocated", QString::number(dicom_file->fbit_alloc(), 10),"0028:0100");
        SetTableRow(58, row, "Bits Stored", QString::number(dicom_file->fbit_stored(), 10),"0028:0101");
        SetTableRow(59, row, "High Bit", QString::number(dicom_file->fhight_bit(), 10),"0028:0102");
        SetTableRow(60, row, "Pixel Representation", QString::number(dicom_file->fpix_rep(), 10),"0028:0103");
        SetTableRow(61, row, "Window Center", QString::fromStdString(dicom_file->fw_c()),"0028:1050");
        SetTableRow(62, row, "Window Width", QString::fromStdString(dicom_file->fw_w()),"0028:1051");
        SetTableRow(63, row, "Rescale Intercept", QString::fromStdString(dicom_file->fr_i()),"0028:1052");
        SetTableRow(64, row, "Rescale Slope", QString::fromStdString(dicom_file->fr_s()),"0028:1053");

        SetTableRow(65, row, "", "**********Group**********","0032");
        SetTableRow(66, row, "Requesting Physician", QString::fromStdString(dicom_file->freq_phy()),"0032:1032");
        SetTableRow(67, row, "Requested Procedure Description", QString::fromStdString(dicom_file->freq_pro_desc()),"0032:1060");

        SetTableRow(68, row, "", "**********Group**********","0040");
        SetTableRow(69, row, "PPS Start Date", QString::fromStdString(dicom_file->fPPS_s_d()),"0040:0244");
        SetTableRow(70, row, "PPS Start Time", QString::fromStdString(dicom_file->fPPS_s_t()),"0040:0245");
        SetTableRow(71, row, "PPS ID", QString::fromStdString(dicom_file->fPPS_ID()),"0040:0253");
        SetTableRow(72, row, "PPS Description", QString::fromStdString(dicom_file->fPPS_desc()),"0040:0254");


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

void MainWindow::copyClip()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setPixmap(QPixmap::grabWidget(ui->graphicsView));
}

void MainWindow::setDrag()
{
    if(ui->actionManual_Windowing->isChecked() == true)
    {
        ui->actionManual_Windowing->setChecked(false);
        ui->actionDrag->setChecked(true);
        dragVal=true;
        windowVal=false;
    }
}

void MainWindow::setWindowing()
{
    if(ui->actionDrag->isChecked() == true)
    {
        ui->actionDrag->setChecked(false);
        ui->actionManual_Windowing->setChecked(true);
        dragVal=false;
        windowVal=true;
    }
}

void MainWindow::zoomChanged_p25()
{
    if (dicom_file)
    {
        ui->graphicsView->scale(1.25,1.25);
    }
}

void MainWindow::zoomChanged_m25()
{
    if (dicom_file)
    {

        ui->graphicsView->scale(1.0/1.25,1.0/1.25);

    }
}


void MainWindow::zoomChanged_100()
{
    if (dicom_file)
    {
        ui->graphicsView->scale(1,1);
    }
}

void MainWindow::rotateRight()
{
    if (dicom_file)
    {
        ui->graphicsView->rotate(90);
    }
}

void MainWindow::rotateLeft()
{
    if (dicom_file)
    {
        ui->graphicsView->rotate(-90);
    }
}

void MainWindow::SetTableRow(int row_nr, QTableWidgetItem row[], QString name, QString value, QString group)
{
    ui->tableWidget->insertRow(row_nr);
    row[3*row_nr].setText(name);
    ui->tableWidget->setItem(row_nr, 0, &row[3*row_nr]);

    row[3*row_nr+1].setText(value);
    ui->tableWidget->setItem(row_nr, 1, &row[3*row_nr+1]);

    row[3*row_nr+2].setText(group);
    ui->tableWidget->setItem(row_nr, 2, &row[3*row_nr+2]);

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

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    setCursor(Qt::ClosedHandCursor);
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    setCursor(Qt::OpenHandCursor);
}

void MainWindow::mouseMoveEvent(QMouseEvent* event) {
    if(dicom_file)
    {
        if(dragVal)
        {
            QPointF delta = ui->graphicsView->mapToScene(ui->graphicsView->LastPanPoint) - ui->graphicsView->mapToScene(ui->graphicsView->EventPos);
            ui->graphicsView->SetCenter(ui->graphicsView->GetCenter() + delta);
        }

        else if(windowVal)
        {
            ui->label->setText(QString("%1 ").arg(QString::number(ui->graphicsView->diffX,10)));
            ui->label2->setText(QString("%1 ").arg(QString::number(ui->graphicsView->diffY,10)));

            dicom_file->setWindowMin(dicom_file->CurrentWindowMin() + ui->graphicsView->diffX);
            dicom_file->setWindowMax(dicom_file->CurrentWindowMax() + ui->graphicsView->diffY);

            ui->label3->setText(QString("%1 ").arg(QString::number(dicom_file->CurrentWindowMin(),10)));
            ui->label4->setText(QString("%1 ").arg(QString::number(dicom_file->CurrentWindowMax(),10)));
            ui->graphicsView->scene()->clear();
            ui->graphicsView->scene()->addPixmap(dicom_file->toPixmap());
        }
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
