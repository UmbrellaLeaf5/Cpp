#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_prt_sc_clicked()
{
    screendialog.exec();
}

void MainWindow::on_text_work_clicked()
{
    textdialog.exec();
}

void MainWindow::on_text_work_2_clicked()
{

}

void MainWindow::on_sett_clicked()
{
    settdialog.exec();
}
