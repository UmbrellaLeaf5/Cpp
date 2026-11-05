/* Основная задача этого примера: показать механизм перемещения на
 * определённое количество точек. Так, например, происходит в большинстве игр,
 * персонаж, которым управляет игрок поворачивает не сразу, а лишь когда закончит
 * выполнять текущее действие, хотя очень пользователь не обращает на это внимание.
 * В этом примере время "реакции" на "желание пользователя" я специально сделаю большим.
 * Наш "герой" будет экземпляром QGrphicsRectItem.
 * За один "шаг" он будет проходить 40 пикселов.
 * Пользователь сможет управлять им с помощью кнопок.
 * Наш "герой" будет менять направление исходя из последней нажатой кнопки.
 *
 * */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Готовим сцену
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0,0,300,300);

    //Добавляем на сцену изображение
    pix = new QGraphicsPixmapItem(QPixmap(":/pix/bg.png"));
    pix->setPos(0,0);
    scene->addItem(pix);



    //Добавляем наш героический объект
    obj = new QGraphicsRectItem(0,0,40,40);
    QColor color = QColor(0,0,0);
    QBrush brush = QBrush(color,Qt::SolidPattern);
    obj->setBrush(brush);
    obj->setPos(40,40);
    scene->addItem(obj);


    //Управлять направлением движения нашего героя будем с помощью переменной status
    status = "right";

    //Использовать для status тип данны QString - это очень расточительно,
    //можно обойтись типом int или даже char,
    //но так будет понятнее, в какую сторону надо будет двигаться.

    //Для хранения информации о новом направлении движения будем использовать
    //переменную new_status
    new_status = status;

    //С помощью этой переменной мы будем отслеживать количество повторений, которые осталось
    //сделать за текущий ход
    repeat = 40;

    //Готовим таймер
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(updateObj()));

    //Запускаем таймер
    timer->start(1000/30);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateObj()
{
    int nx,ny;
    if(repeat == 0){
        repeat = 40;
        status = new_status;
    }
    if(status == "right"){
        nx = obj->pos().x() + 1;
        ny = obj->pos().y();
    }else if(status == "left"){
        nx = obj->pos().x() - 1;
        ny = obj->pos().y();
    }else if(status == "top"){
        ny = obj->pos().y() - 1;
        nx = obj->pos().x();
    }else if(status == "down"){
        ny = obj->pos().y() + 1;
        nx = obj->pos().x();
    }
    obj->setPos(nx,ny);
    repeat --;
}

void MainWindow::on_pushButton_3_clicked()
{
    new_status = "down";
}

void MainWindow::on_pushButton_4_clicked()
{
    new_status = "left";
}

void MainWindow::on_pushButton_2_clicked()
{
    new_status = "top";
}

void MainWindow::on_pushButton_clicked()
{
    new_status = "right";
}
