#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new gameView();
    this->setCentralWidget(game);
}

MainWindow::~MainWindow()
{
    delete ui;
}
