#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>

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

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    DicomItem *dicom_file;
};

#endif // MAINWINDOW_H
