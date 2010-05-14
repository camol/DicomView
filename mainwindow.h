#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    void SetTableRow(int row_nr, QTableWidgetItem row[], QString name, QString value);

public slots:
    void Open();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
