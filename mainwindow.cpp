#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QStringList>
#include <QList>
#include <QTreeWidget>
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
    QStringList files = QFileDialog::getOpenFileNames(this,"Select one or more DICOM files to open","","DICOM (*.dcm)");
    QStringList list = files;

    if (!QStringList(list).isEmpty())
    {

        //int amount = QStringList(list).size();

        QTreeWidgetItem *all_patients = new QTreeWidgetItem(ui->treeWidget);
        all_patients->setText(0, tr("All Patients"));

        QTreeWidgetItem *name = new QTreeWidgetItem(all_patients);
        name->setText(0, tr("No Name"));

        QTreeWidgetItem *modality = new QTreeWidgetItem(name);
        modality->setText(0, tr("modality"));

        QTreeWidgetItem *series_desc = new QTreeWidgetItem(modality);
        series_desc->setText(0, tr("series_desc"));


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
