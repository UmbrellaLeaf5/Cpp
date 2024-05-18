#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Создаём экземпляр класса
    game = new gameView();


    //Добавляем виджет, созданный динамически, в горизонтальный компоновщик,
    //добавленный в режиме дизайна.
    ui->horizontalLayout->addWidget(game);

}

MainWindow::~MainWindow()
{
    delete ui;
}
