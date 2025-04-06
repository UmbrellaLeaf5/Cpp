#include "widget.h"
#include "ui_widget.h"
#include <QTabBar>
#include "stylehelper.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->Init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::startGame()
{
    ui->tabWidget->setCurrentIndex(1);
}

void Widget::help()
{
    ui->tabWidget->setCurrentIndex(2);
}

void Widget::settings()
{
    ui->tabWidget->setCurrentIndex(3);
}

void Widget::back()
{
    ui->tabWidget->setCurrentIndex(0);
}

void Widget::Init()
{
    QTabBar *tabbar = ui->tabWidget->findChild<QTabBar *>();
    tabbar->hide();
    ui->tabWidget->setCurrentIndex(0);
    connect(ui->gameButton, &QPushButton::clicked, this, &Widget::startGame);
    connect(ui->helpButton, &QPushButton::clicked, this, &Widget::help);
    connect(ui->settingsButton, &QPushButton::clicked, this, &Widget::settings);
    connect(ui->BackButton_1, &QPushButton::clicked, this, &Widget::back);
    connect(ui->BackButton_2, &QPushButton::clicked, this, &Widget::back);
    connect(ui->BackButton_3, &QPushButton::clicked, this, &Widget::back);
    ui->gameButton->setStyleSheet(StyleHelper::getGameBtnStyle());
    ui->helpButton->setStyleSheet(StyleHelper::getHelpBtnStyle());
}


