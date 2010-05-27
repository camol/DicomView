#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QPointF>

namespace Ui {
    class MainWindow;
}

class DicomItem;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    void SetTableRow(int row_nr, QTableWidgetItem row[], QString name, QString value);
    double zvalue;
    bool dragVal;
    bool windowVal;


public slots:
    void Open();
    void PresDef();
    void PresSkull();
    void PresLung();
    void PresAbdomen();
    void PresBone();
    void PresSpine();
    void zoomChanged_p25();
    void zoomChanged_m25();
    void zoomChanged_100();
    void rotateRight();
    void rotateLeft();
    void setDrag();
    void setWindowing();

protected:
    void changeEvent(QEvent *e);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);

private:
    Ui::MainWindow *ui;
    DicomItem *dicom_file;
};

#endif // MAINWINDOW_H
