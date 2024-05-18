/* Перемещение QGraphicsItem. Часть 4
 * 6. Добавим на сцену картинку с клетками.
 * В большинстве игр для контроля возможности перемещения объекта используется
 * контроль его положения на карте, которая представляется в виде массива.
 * Чтобы это реализовать, необходимо разобраться с тем, как узнать, где находится наш объект.
 * Для этого добавим тестовые поля и будем туда выводить номер клетки.
 * Делать это мы будем с помощью функции updateTexPos();
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <math.h>
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

    //6

    pix = new QGraphicsPixmapItem(QPixmap(":/pix/bg.png"));
    scene->addItem(pix);
    pix->setPos(0,0);




    //3
    rect = new QGraphicsRectItem(0,0,40,40);
    QBrush brush = QBrush(QColor(0,0,200),Qt::SolidPattern);
    rect->setBrush(brush);
    rect->setPen(Qt::PenStyle::NoPen);
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
    updateTexPos();
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

void MainWindow::updateTexPos(){
    //Для упрощения понимания наше клеточное поле размещено в координатах 0,0
    //Это позволит нам отказаться от нескольких дополнительных дейтсвий.
    //Получаем позицию квадратика
    int rectX = rect->pos().x();
    int rectY = rect->pos().y();

    //ширина нашей клетки равна 40, плюс расстояние 2 пиксела между клетками.
    //зная это мы можем точно сказать в какой клетке находится наш квадрат

    int numX = rectX / (40 + 2);
    int numY = rectY / (40 + 2);

    ui->lineEdit->setText(QString::number(numX));
    ui->lineEdit_2->setText(QString::number(numY));

    if((numX==3)&&(numY==0)){
        setWindowTitle("Стой!");
        timer->stop();
    }

}
