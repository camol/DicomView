/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 30. May 21:38:14 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>
#include "MyGraphicsView.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionQuit_Program;
    QAction *actionDefault;
    QAction *actionSkull;
    QAction *actionLung;
    QAction *actionAbdomen;
    QAction *actionMediastinum;
    QAction *actionBone;
    QAction *actionSpine;
    QAction *actionZoom_50;
    QAction *actionZoom_51;
    QAction *actionZoom_100;
    QAction *actionRotate_Right;
    QAction *actionRotate_Left;
    QAction *action;
    QAction *bWindowing;
    QAction *actionDrag;
    QAction *actionManual_Windowing;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_img;
    MyGraphicsView *graphicsView;
    QLabel *lname;
    QLabel *lmod;
    QLabel *lseries;
    QLabel *ldate;
    QLabel *label;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *labelzoom;
    QWidget *tab_tags;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QTreeWidget *treeWidget;
    QFrame *line;
    QMenuBar *menuBar;
    QMenu *menuOpen;
    QMenu *menuImage;
    QMenu *menuPresets;
    QMenu *menuZoom;
    QMenu *menuRotate;
    QMenu *menuCursor;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(743, 520);
        MainWindow->setMinimumSize(QSize(743, 520));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionQuit_Program = new QAction(MainWindow);
        actionQuit_Program->setObjectName(QString::fromUtf8("actionQuit_Program"));
        actionDefault = new QAction(MainWindow);
        actionDefault->setObjectName(QString::fromUtf8("actionDefault"));
        actionSkull = new QAction(MainWindow);
        actionSkull->setObjectName(QString::fromUtf8("actionSkull"));
        actionLung = new QAction(MainWindow);
        actionLung->setObjectName(QString::fromUtf8("actionLung"));
        actionAbdomen = new QAction(MainWindow);
        actionAbdomen->setObjectName(QString::fromUtf8("actionAbdomen"));
        actionMediastinum = new QAction(MainWindow);
        actionMediastinum->setObjectName(QString::fromUtf8("actionMediastinum"));
        actionBone = new QAction(MainWindow);
        actionBone->setObjectName(QString::fromUtf8("actionBone"));
        actionSpine = new QAction(MainWindow);
        actionSpine->setObjectName(QString::fromUtf8("actionSpine"));
        actionZoom_50 = new QAction(MainWindow);
        actionZoom_50->setObjectName(QString::fromUtf8("actionZoom_50"));
        actionZoom_51 = new QAction(MainWindow);
        actionZoom_51->setObjectName(QString::fromUtf8("actionZoom_51"));
        actionZoom_100 = new QAction(MainWindow);
        actionZoom_100->setObjectName(QString::fromUtf8("actionZoom_100"));
        actionRotate_Right = new QAction(MainWindow);
        actionRotate_Right->setObjectName(QString::fromUtf8("actionRotate_Right"));
        actionRotate_Left = new QAction(MainWindow);
        actionRotate_Left->setObjectName(QString::fromUtf8("actionRotate_Left"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action->setCheckable(true);
        action->setChecked(true);
        bWindowing = new QAction(MainWindow);
        bWindowing->setObjectName(QString::fromUtf8("bWindowing"));
        bWindowing->setCheckable(true);
        bWindowing->setChecked(false);
        actionDrag = new QAction(MainWindow);
        actionDrag->setObjectName(QString::fromUtf8("actionDrag"));
        actionDrag->setCheckable(true);
        actionDrag->setChecked(true);
        actionManual_Windowing = new QAction(MainWindow);
        actionManual_Windowing->setObjectName(QString::fromUtf8("actionManual_Windowing"));
        actionManual_Windowing->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(200, 0, 529, 471));
        tabWidget->setMinimumSize(QSize(505, 426));
        tab_img = new QWidget();
        tab_img->setObjectName(QString::fromUtf8("tab_img"));
        graphicsView = new MyGraphicsView(tab_img);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(-5, 1, 531, 451));
        graphicsView->setMinimumSize(QSize(531, 451));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        graphicsView->setPalette(palette);
        lname = new QLabel(tab_img);
        lname->setObjectName(QString::fromUtf8("lname"));
        lname->setGeometry(QRect(10, 10, 61, 21));
        lname->setMinimumSize(QSize(61, 21));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        lname->setPalette(palette1);
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        lname->setFont(font);
        lmod = new QLabel(tab_img);
        lmod->setObjectName(QString::fromUtf8("lmod"));
        lmod->setGeometry(QRect(10, 40, 61, 21));
        lmod->setMinimumSize(QSize(61, 21));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lmod->setPalette(palette2);
        lmod->setFont(font);
        lseries = new QLabel(tab_img);
        lseries->setObjectName(QString::fromUtf8("lseries"));
        lseries->setGeometry(QRect(10, 350, 121, 21));
        lseries->setMinimumSize(QSize(61, 21));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lseries->setPalette(palette3);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        lseries->setFont(font1);
        ldate = new QLabel(tab_img);
        ldate->setObjectName(QString::fromUtf8("ldate"));
        ldate->setGeometry(QRect(360, 60, 61, 21));
        ldate->setMinimumSize(QSize(61, 21));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush5(QColor(120, 120, 120, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        ldate->setPalette(palette4);
        ldate->setFont(font1);
        label = new QLabel(tab_img);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 30, 81, 51));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        label->setPalette(palette5);
        label2 = new QLabel(tab_img);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(350, 40, 81, 51));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        label2->setPalette(palette6);
        label3 = new QLabel(tab_img);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(210, 110, 81, 41));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        label3->setPalette(palette7);
        label4 = new QLabel(tab_img);
        label4->setObjectName(QString::fromUtf8("label4"));
        label4->setGeometry(QRect(370, 110, 81, 51));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        label4->setPalette(palette8);
        labelzoom = new QLabel(tab_img);
        labelzoom->setObjectName(QString::fromUtf8("labelzoom"));
        labelzoom->setGeometry(QRect(50, 292, 81, 31));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        labelzoom->setPalette(palette9);
        tabWidget->addTab(tab_img, QString());
        tab_tags = new QWidget();
        tab_tags->setObjectName(QString::fromUtf8("tab_tags"));
        horizontalLayout = new QHBoxLayout(tab_tags);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableWidget = new QTableWidget(tab_tags);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setFont(font2);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font2);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setMinimumSize(QSize(505, 426));
        tableWidget->setBaseSize(QSize(0, 0));
        tableWidget->setTextElideMode(Qt::ElideMiddle);
        tableWidget->setColumnCount(2);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(200);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        horizontalLayout->addWidget(tableWidget);

        tabWidget->addTab(tab_tags, QString());
        treeWidget = new QTreeWidget(centralWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(11, 1, 181, 461));
        treeWidget->setMinimumSize(QSize(181, 461));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(190, 0, 16, 449));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 743, 21));
        menuOpen = new QMenu(menuBar);
        menuOpen->setObjectName(QString::fromUtf8("menuOpen"));
        menuImage = new QMenu(menuBar);
        menuImage->setObjectName(QString::fromUtf8("menuImage"));
        menuPresets = new QMenu(menuImage);
        menuPresets->setObjectName(QString::fromUtf8("menuPresets"));
        menuZoom = new QMenu(menuImage);
        menuZoom->setObjectName(QString::fromUtf8("menuZoom"));
        menuRotate = new QMenu(menuImage);
        menuRotate->setObjectName(QString::fromUtf8("menuRotate"));
        menuCursor = new QMenu(menuBar);
        menuCursor->setObjectName(QString::fromUtf8("menuCursor"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuOpen->menuAction());
        menuBar->addAction(menuImage->menuAction());
        menuBar->addAction(menuCursor->menuAction());
        menuOpen->addAction(actionOpen);
        menuOpen->addSeparator();
        menuOpen->addAction(actionQuit_Program);
        menuImage->addAction(menuPresets->menuAction());
        menuImage->addAction(menuZoom->menuAction());
        menuImage->addAction(menuRotate->menuAction());
        menuPresets->addAction(actionDefault);
        menuPresets->addAction(actionSkull);
        menuPresets->addAction(actionLung);
        menuPresets->addAction(actionAbdomen);
        menuPresets->addAction(actionMediastinum);
        menuPresets->addAction(actionBone);
        menuPresets->addAction(actionSpine);
        menuZoom->addAction(actionZoom_50);
        menuZoom->addAction(actionZoom_51);
        menuZoom->addSeparator();
        menuZoom->addAction(actionZoom_100);
        menuRotate->addAction(actionRotate_Right);
        menuRotate->addAction(actionRotate_Left);
        menuCursor->addAction(actionDrag);
        menuCursor->addAction(actionManual_Windowing);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit_Program, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open...         ", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionQuit_Program->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionDefault->setText(QApplication::translate("MainWindow", "Default", 0, QApplication::UnicodeUTF8));
        actionSkull->setText(QApplication::translate("MainWindow", "Skull", 0, QApplication::UnicodeUTF8));
        actionLung->setText(QApplication::translate("MainWindow", "Lung", 0, QApplication::UnicodeUTF8));
        actionAbdomen->setText(QApplication::translate("MainWindow", "Abdomen", 0, QApplication::UnicodeUTF8));
        actionMediastinum->setText(QApplication::translate("MainWindow", "Mediastinum", 0, QApplication::UnicodeUTF8));
        actionBone->setText(QApplication::translate("MainWindow", "Bone", 0, QApplication::UnicodeUTF8));
        actionSpine->setText(QApplication::translate("MainWindow", "Spine", 0, QApplication::UnicodeUTF8));
        actionZoom_50->setText(QApplication::translate("MainWindow", "Zoom +25%   ", 0, QApplication::UnicodeUTF8));
        actionZoom_50->setShortcut(QApplication::translate("MainWindow", "Ctrl+=", 0, QApplication::UnicodeUTF8));
        actionZoom_51->setText(QApplication::translate("MainWindow", "Zoom -25% ", 0, QApplication::UnicodeUTF8));
        actionZoom_51->setShortcut(QApplication::translate("MainWindow", "Ctrl+Backspace", 0, QApplication::UnicodeUTF8));
        actionZoom_100->setText(QApplication::translate("MainWindow", "Zoom 100%", 0, QApplication::UnicodeUTF8));
        actionRotate_Right->setText(QApplication::translate("MainWindow", "Rotate Right", 0, QApplication::UnicodeUTF8));
        actionRotate_Right->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        actionRotate_Left->setText(QApplication::translate("MainWindow", "Rotate Left", 0, QApplication::UnicodeUTF8));
        actionRotate_Left->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MainWindow", "Drag", 0, QApplication::UnicodeUTF8));
        bWindowing->setText(QApplication::translate("MainWindow", "Manual Windowing", 0, QApplication::UnicodeUTF8));
        actionDrag->setText(QApplication::translate("MainWindow", "Drag", 0, QApplication::UnicodeUTF8));
        actionManual_Windowing->setText(QApplication::translate("MainWindow", "Manual Windowing", 0, QApplication::UnicodeUTF8));
        lname->setText(QString());
        lmod->setText(QString());
        lseries->setText(QString());
        ldate->setText(QString());
        label->setText(QString());
        label2->setText(QString());
        label3->setText(QString());
        label4->setText(QString());
        labelzoom->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_img), QApplication::translate("MainWindow", "Image", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Tag Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Value", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_tags), QApplication::translate("MainWindow", "Tags", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Dicom Browser", 0, QApplication::UnicodeUTF8));
        menuOpen->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuImage->setTitle(QApplication::translate("MainWindow", "Image", 0, QApplication::UnicodeUTF8));
        menuPresets->setTitle(QApplication::translate("MainWindow", "Presets", 0, QApplication::UnicodeUTF8));
        menuZoom->setTitle(QApplication::translate("MainWindow", "Zoom", 0, QApplication::UnicodeUTF8));
        menuRotate->setTitle(QApplication::translate("MainWindow", "Rotate", 0, QApplication::UnicodeUTF8));
        menuCursor->setTitle(QApplication::translate("MainWindow", "Cursor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
