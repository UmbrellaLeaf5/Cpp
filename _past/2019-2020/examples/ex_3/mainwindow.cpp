/* Перемещение QGraphicsItem. Часть 3
 * Очень многие игры построены так, что им хватает одного таймера для
 * построения всего визуального ряда, но бывает так, что это не удобно.
 * 5. Добавим ещё один таймер. Таймер буде запускаться, когда квадрат
 * доберётся до края сцены. В данном случае контролируются координаты объекта.
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //2
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    QBrush sc_brush = QBrush(QColor(200,200,200),Qt::SolidPattern);
    scene->setBackgroundBrush(sc_brush);
    scene->setSceneRect(0,0,400,400);

    //3
    rect = new QGraphicsRectItem(0,0,50,50);
    QBrush brush = QBrush(QColor(50,0,0),Qt::SolidPattern);
    rect->setBrush(brush);
    scene->addItem(rect);
    rect->setPos(0,0);

    //4
    timer = new QTimer;
    timer ->setInterval(1000/30);
    connect(timer,SIGNAL(timeout()),this,SLOT(updatePosition()));
    timer->start();

    //5
    sc_timer = new QTimer;
    sc_timer ->setInterval(500);
    connect(sc_timer,SIGNAL(timeout()),this,SLOT(alarm()));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    rect->setPos(0,0);
}

void MainWindow::updatePosition(){
    qreal newX = rect->pos().x() + 1;
    qreal newY = rect->pos().y();
    rect->setPos(newX,newY);
    if((newX > 350)&&(sc_timer->isActive() == false)){
        sc_timer->start();
        setWindowTitle("Тревога! Квадратик сбежал!");

    }
}

void MainWindow::alarm(){
    qDebug() << "alarm";
    QColor color;
    if((alarm_count%2) == 0){
        color = QColor(200,0,0);
    }else{
        color = QColor(200,200,200);
    }

    scene->setBackgroundBrush(QBrush(color,Qt::SolidPattern));
    alarm_count ++;
    if(rect->pos().x()<=350){
        sc_timer->stop();
        alarm_count = 0;
        scene->setBackgroundBrush(QBrush(QColor(200,200,200),Qt::SolidPattern));
         setWindowTitle("Он вернулся...");
    }
}
