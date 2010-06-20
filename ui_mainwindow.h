/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 20. Jun 11:23:30 2010
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
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeView>
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
    QAction *actionCopy_to_Clipboard;
    QAction *actionOpen_Folder;
    QAction *actionHelp;
    QAction *actionAbout_DicomView;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *line;
    QTabWidget *tabWidget;
    QWidget *tab_img;
    QGridLayout *gridLayout_2;
    MyGraphicsView *graphicsView;
    QWidget *tab_tags;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QTreeView *treeView;
    QMenuBar *menuBar;
    QMenu *menuOpen;
    QMenu *menuImage;
    QMenu *menuPresets;
    QMenu *menuZoom;
    QMenu *menuRotate;
    QMenu *menuCursor;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(774, 552);
        MainWindow->setMinimumSize(QSize(774, 552));
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
        actionCopy_to_Clipboard = new QAction(MainWindow);
        actionCopy_to_Clipboard->setObjectName(QString::fromUtf8("actionCopy_to_Clipboard"));
        actionOpen_Folder = new QAction(MainWindow);
        actionOpen_Folder->setObjectName(QString::fromUtf8("actionOpen_Folder"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionAbout_DicomView = new QAction(MainWindow);
        actionAbout_DicomView->setObjectName(QString::fromUtf8("actionAbout_DicomView"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(505, 426));
        tab_img = new QWidget();
        tab_img->setObjectName(QString::fromUtf8("tab_img"));
        gridLayout_2 = new QGridLayout(tab_img);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphicsView = new MyGraphicsView(tab_img);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
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

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);

        tabWidget->addTab(tab_img, QString());
        tab_tags = new QWidget();
        tab_tags->setObjectName(QString::fromUtf8("tab_tags"));
        horizontalLayout = new QHBoxLayout(tab_tags);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableWidget = new QTableWidget(tab_tags);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem2->setFont(font);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setMinimumSize(QSize(505, 426));
        tableWidget->setBaseSize(QSize(0, 0));
        tableWidget->setTextElideMode(Qt::ElideMiddle);
        tableWidget->setColumnCount(3);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(200);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        horizontalLayout->addWidget(tableWidget);

        tabWidget->addTab(tab_tags, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 2, 1);

        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setMinimumSize(QSize(214, 0));
        treeView->setMaximumSize(QSize(214, 16777215));

        gridLayout->addWidget(treeView, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 774, 21));
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
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
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
        menuBar->addAction(menuHelp->menuAction());
        menuOpen->addAction(actionOpen);
        menuOpen->addAction(actionOpen_Folder);
        menuOpen->addSeparator();
        menuOpen->addAction(actionQuit_Program);
        menuImage->addAction(menuPresets->menuAction());
        menuImage->addAction(menuZoom->menuAction());
        menuImage->addAction(menuRotate->menuAction());
        menuImage->addSeparator();
        menuImage->addAction(actionCopy_to_Clipboard);
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
        menuHelp->addAction(actionHelp);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout_DicomView);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit_Program, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(1);


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
        actionCopy_to_Clipboard->setText(QApplication::translate("MainWindow", "Copy to Clipboard", 0, QApplication::UnicodeUTF8));
        actionOpen_Folder->setText(QApplication::translate("MainWindow", "Open Folder", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        actionAbout_DicomView->setText(QApplication::translate("MainWindow", "About DicomView", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_img), QApplication::translate("MainWindow", "Image", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Tag Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Value", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Group:Element", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_tags), QApplication::translate("MainWindow", "Tags", 0, QApplication::UnicodeUTF8));
        menuOpen->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuImage->setTitle(QApplication::translate("MainWindow", "Image", 0, QApplication::UnicodeUTF8));
        menuPresets->setTitle(QApplication::translate("MainWindow", "Presets", 0, QApplication::UnicodeUTF8));
        menuZoom->setTitle(QApplication::translate("MainWindow", "Zoom", 0, QApplication::UnicodeUTF8));
        menuRotate->setTitle(QApplication::translate("MainWindow", "Rotate", 0, QApplication::UnicodeUTF8));
        menuCursor->setTitle(QApplication::translate("MainWindow", "Cursor", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
