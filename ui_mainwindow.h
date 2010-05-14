/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 14. May 15:06:37 2010
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
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionQuit_Program;
    QWidget *centralWidget;
    QTreeWidget *treeWidget;
    QTabWidget *tabWidget;
    QWidget *tab_img;
    QWidget *tab_tags;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *menuOpen;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(631, 522);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionQuit_Program = new QAction(MainWindow);
        actionQuit_Program->setObjectName(QString::fromUtf8("actionQuit_Program"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        treeWidget = new QTreeWidget(centralWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(0, 1, 171, 461));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(180, 0, 441, 461));
        tab_img = new QWidget();
        tab_img->setObjectName(QString::fromUtf8("tab_img"));
        tabWidget->addTab(tab_img, QString());
        tab_tags = new QWidget();
        tab_tags->setObjectName(QString::fromUtf8("tab_tags"));
        tableWidget = new QTableWidget(tab_tags);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(-10, 0, 451, 441));
        tableWidget->setMinimumSize(QSize(431, 0));
        tableWidget->setColumnCount(2);
        tabWidget->addTab(tab_tags, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 631, 21));
        menuOpen = new QMenu(menuBar);
        menuOpen->setObjectName(QString::fromUtf8("menuOpen"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuOpen->menuAction());
        menuOpen->addAction(actionOpen);
        menuOpen->addSeparator();
        menuOpen->addAction(actionQuit_Program);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit_Program, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionQuit_Program->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Dicom Browser", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_img), QApplication::translate("MainWindow", "Image", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Tag Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Value", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_tags), QApplication::translate("MainWindow", "Tags", 0, QApplication::UnicodeUTF8));
        menuOpen->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
