#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new gameView();
    ui->horizontalLayout->addWidget(game);

}

MainWindow::~MainWindow()
{
    delete ui;
}
