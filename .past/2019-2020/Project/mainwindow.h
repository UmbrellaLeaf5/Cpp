#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "screendialog.h"
#include "textdialog.h"
#include "settdialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_prt_sc_clicked();

    void on_text_work_clicked();

    void on_text_work_2_clicked();

    void on_sett_clicked();

private:
    Ui::MainWindow *ui;
    ScreenDialog screendialog;
    TextDialog textdialog;
    SettDialog settdialog;

};
#endif // MAINWINDOW_H
