
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0,0,300,300);
    //ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    pix = new QGraphicsPixmapItem(QPixmap(":/pix/bg.png"));
    pix->setPos(0,0);
    scene->addItem(pix);

    obj = new QGraphicsRectItem(0,0,40,40);
    QColor color = QColor(0,200,200);
    QBrush brush = QBrush(color,Qt::SolidPattern);
    obj->setBrush(brush);
    obj->setPos(40,40);

    scene->addItem(obj);

    status = "right";
    new_status = status;

    repeat = 10;


    //***********************************************************
    scene->installEventFilter(this);
    int pointX, pointY;
    for(int jY= 0; jY<7; jY++)
    {
        for(int jX= 0; jX<7; jX++)
        {
            if(matrix[jY][jX] == 0)
            {
                pointsArr[jY][jX] = new QGraphicsRectItem(0,0,10,10);
                pointsArr[jY][jX]->setPen(Qt::PenStyle::NoPen);
                pointsArr[jY][jX]->setBrush(QBrush(QColor(0,0,200),Qt::SolidPattern));
                scene->addItem(pointsArr[jY][jX]);
                pointX = 40 * jX + ((40-10)/2);
                pointY = 40 * jY + ((40-10)/2);
                pointsArr[jY][jX]->setPos(pointX,pointY);
                matrix[jY][jX] = 1;
        }}}


    //*********************************************************


    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(updateObj()));

    timer->start(1000/30);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::updateObj()
{

    qreal nx,ny;
    int celx, cely;
    int new_celx, new_cely;


    if(repeat == 0){

        //Получаем данные о клетке в которой находится герой
        celx = obj->pos().x() / 40;
        cely = obj->pos().y() / 40;

        if(matrix[cely][celx]==1){
            pointsArr[cely][celx]->hide();


        }


        //Получаем данные о клетке в которую собираемся
        if(new_status == "right") {
            new_celx = celx + 1;
            new_cely = cely;
        }else if(new_status == "left") {
            new_celx = celx - 1;
            new_cely = cely;
        }else if(new_status == "top") {
            new_celx = celx;
            new_cely = cely - 1;
        }else if(new_status == "down") {
            new_celx = celx;
            new_cely = cely + 1;
        }
        //Смотрим, можно ли идти на ту клетку, в которую собрался двигаться наш герой.
        //Если да, то сбрасываем счётчик повторений и меняем статус.
        if(matrix[new_cely][new_celx]!= -1){
            repeat = 10;
            status = new_status;
        }
    }


    //Получаем данные о клетке в которой находится герой
    if(repeat == 5){
        celx = obj->pos().x() / 40;
        cely = obj->pos().y() / 40;

        if(matrix[cely][celx]==1){
            pointsArr[cely][celx]->hide();
        }
    }

    if(repeat != 0){
        if(status == "right"){
            nx = obj->pos().x() + 4;
            ny = obj->pos().y();
        }else if(status == "left"){
            nx = obj->pos().x() - 4;
            ny = obj->pos().y();
        }else if(status == "top"){
            ny = obj->pos().y() - 4;
            nx = obj->pos().x();
        }else if(status == "down"){
            ny = obj->pos().y() + 4;
            nx = obj->pos().x();
        }
        obj->setPos(nx,ny);
        repeat --;
    }
}



bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
    Q_UNUSED(obj)

    if (event->type() == QEvent::KeyPress) {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);

        switch (key->key()) {
        case Qt::Key_Left:
            new_status = "left";
            break;
        case Qt::Key_Up:
            new_status = "top";
            break;
        case Qt::Key_Right:
            new_status = "right";
            break;
        case Qt::Key_Down:

            new_status = "down";
            break;
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

