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

    //QObject::connect(ui->actionOpenButton,SIGNAL(clicked()),this,SLOT(Open()));
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

        QString text = QString::number(dicom_file->fpat_name(), 10);

        QTreeWidgetItem *name = new QTreeWidgetItem(all_patients);
        name->setText(0, text);
/*
        QTreeWidgetItem *modality = new QTreeWidgetItem(name);
        modality->setText(0, tr("modality"));

        QTreeWidgetItem *series_desc = new QTreeWidgetItem(modality);
        series_desc->setText(0, tr("series_desc"));
        */


        //int amount = QStringList(list).size();

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
