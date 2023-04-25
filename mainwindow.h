#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"debuglogger.h"
#include "classrobot.h"
#include"readdata.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    classrobot robot ;



private:
    Ui::MainWindow *ui;
    QStringListModel *m_stringListModel;

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
};

#endif // MAINWINDOW_H
