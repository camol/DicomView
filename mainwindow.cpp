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
    QString fname = QFileDialog::getOpenFileName();

    if (fname != "")
    {

        dicom::DataSet dset;
        dicom::Read(fname.toStdString(), dset);

        DicomItem *dicom_file = new DicomItem(dset);


        QTreeWidgetItem *all_patients = new QTreeWidgetItem(ui->treeWidget);
        all_patients->setText(0, tr("All Patients"));

        QTreeWidgetItem *name = new QTreeWidgetItem(all_patients);
        name->setText(0, QString::number(dicom_file->fhight_bit(), 10));


        /*Wyswietlanie Tagów*/
        ui->tableWidget->insertRow(0);
        QTableWidgetItem *a11 = new QTableWidgetItem(0);
        a11->setText( "High Bit" );
        ui->tableWidget->setItem( 0, 0, a11 );
        QTableWidgetItem *a12 = new QTableWidgetItem(0);
        a12->setText( QString::number(dicom_file->fhight_bit(), 10) );
        ui->tableWidget->setItem( 0, 1, a12 );


        ui->tableWidget->insertRow(1);
        QTableWidgetItem *a21 = new QTableWidgetItem(0);
        a21->setText( "Bits Allocated" );
        ui->tableWidget->setItem( 1, 0, a21 );
        QTableWidgetItem *a22 = new QTableWidgetItem(0);
        a22->setText( QString::number(dicom_file->fbit_alloc(), 10) );
        ui->tableWidget->setItem( 1, 1, a22 );


        ui->tableWidget->insertRow(2);
        QTableWidgetItem *a31 = new QTableWidgetItem(0);
        a31->setText( "Bits Stored" );
        ui->tableWidget->setItem( 2, 0, a31 );
        QTableWidgetItem *a32 = new QTableWidgetItem(0);
        a32->setText( QString::number(dicom_file->fbit_stored(), 10) );
        ui->tableWidget->setItem( 2, 1, a32 );

/*
        QTreeWidgetItem *modality = new QTreeWidgetItem(name);
        modality->setText(0, tr("modality"));

        QTreeWidgetItem *series_desc = new QTreeWidgetItem(modality);
        series_desc->setText(0, tr("series_desc"));
        */




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
