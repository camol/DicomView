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


        /***************Wyswietlanie Tagów***********************************/
        /********************************************************************/
        QTableWidgetItem *row = new QTableWidgetItem[20];

        SetTableRow(0, row, "High Bit", QString::number(dicom_file->fhight_bit(), 10));
        SetTableRow(1, row, "Bits Allocated", QString::number(dicom_file->fbit_alloc(), 10));
        SetTableRow(2, row, "Bits Stored", QString::number(dicom_file->fbit_stored(), 10));
        SetTableRow(3, row, "Window Width", QString::fromStdString(dicom_file->fw_w()));
        //SetTableRow(3, row, "Patient Name", QString::fromStdString(dicom_file->fpat_name()));

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
