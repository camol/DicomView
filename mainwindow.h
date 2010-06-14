#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QPointF>
#include <QClipboard>

namespace Ui {
    class MainWindow;
}

class DicomItem;


/**
* @page MainWindow Class MainWindow.
* Main class which controls everything in the project.
*/

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:

    /**
    * SetTableRow.
    * @param int
    * @param QTableWidgetItem
    * @param QString
    * @param QString
    * @param QString
    * @return void
    */
    void SetTableRow(int row_nr, QTableWidgetItem row[], QString name, QString value, QString group);
    /**
    * Method which puts a new row of DICOM Tag and displays its name, value and group in the table.
    */


    bool dragVal;
    bool windowVal;


public slots:

    /**
    * Open.
    * @param void
    * @return void
    */
    void Open();
    /**
    * Method that opens the choosen DICOM file and displays the picture and Tags using methods from DicomItem Class.
    */


    /**
    * Sets the default min and max window levels.
    */
    void PresDef();


    /**
    * Sets the min and max window levels best for skull diplaying.
    */
    void PresSkull();

    /**
    * Sets the min and max window levels best for lung diplaying.
    */
    void PresLung();

    /**
    * Sets the min and max window levels best for abdomen diplaying.
    */
    void PresAbdomen();

    /**
    * Sets the min and max window levels best for bone diplaying.
    */
    void PresBone();

    /**
    * Sets the min and max window levels best for spine diplaying.
    */
    void PresSpine();

    /**
    * Zoom in the picture by 25%.
    */
    void zoomChanged_p25();

    /**
    * Zoom out the picture by 25%.
    */
    void zoomChanged_m25();

    /**
    * Zoom 100%.
    */
    void zoomChanged_100();

    /**
    * Rotate right the picture by 90 degres.
    */
    void rotateRight();

    /**
    * Rotate left the picture by 90 degres.
    */
    void rotateLeft();

    /**
    * Enables mouse drag.
    */
    void setDrag();

    /**
    * Enables manual windowing using the mouse move
    */
    void setWindowing();

    /**
    * Copies the picture to clipboard
    */
    void copyClip();

protected:
    void changeEvent(QEvent *e);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);

    /**
    * mouseMoveEvent.
    * @param const QMouseEvent*
    * @return void
    */
    virtual void mouseMoveEvent(QMouseEvent* event);
    /**
    * Method which takes over the mouse event from MyGraphicsView and does the manual windowing or dragging depending on the
    * choosen option.
    */

private:
    Ui::MainWindow *ui;
    DicomItem *dicom_file;
};

#endif // MAINWINDOW_H
