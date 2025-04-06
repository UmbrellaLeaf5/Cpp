/* Осталось разобраться с  матрицей...
 * Добавим к предыдущему примеру двумерный массив.
 * Каждый элемент массива - это клетка.
 * Если в неё можно идти, то значение равно нулю, если нет, то -1
 * Матрица объявлена в заголовочном файле. Её значения совпадают
 * с клетками нарисованного поля.
 * В некоторых играх, таких как ПАКМАН, например, герой не всегда поворачивается туда,
 * куда ему велит пользователь. Если пользователь жмёт клавишу вправо, а справа стена, то
 * пакман продолжает себе спокойно идти, куда шёл.
 * Но для начала упростим задачу, выполняя все действия пользователя.
 * */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0,0,300,300);

    pix = new QGraphicsPixmapItem(QPixmap(":/pix/bg.png"));
    pix->setPos(0,0);
    scene->addItem(pix);

    obj = new QGraphicsRectItem(0,0,40,40);
    QColor color = QColor(0,0,0);
    QBrush brush = QBrush(color,Qt::SolidPattern);
    obj->setBrush(brush);
    obj->setPos(40,40);
    scene->addItem(obj);

    status = "right";
    new_status = status;

    repeat = 40;

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

    int nx,ny;
    int celx, cely;
    int new_celx, new_cely;
    if(repeat == 0){
        //Получаем данные о клетке в которой находится герой
        celx = obj->pos().x() / 40;
        cely = obj->pos().y() / 40;

        //Получаем данные о клетке в которую собираемся
        if(new_status == "right") {
            new_celx = celx + 1;
            new_cely = cely;
        }
        if(new_status == "left") {
            new_celx = celx - 1;
            new_cely = cely;
        }
        if(new_status == "top") {
            new_celx = celx;
            new_cely = cely - 1;
        }
        if(new_status == "down") {
            new_celx = celx;
            new_cely = cely + 1;
        }
        //Смотрим, можно ли идти на ту клетку, в которую собрался двигаться наш герой.
        //Если да, то сбрасываем счётчик повторений и меняем статус.
        if(matrix[new_cely][new_celx]== 0){
            repeat = 40;
            status = new_status;
        }
    }
    if(repeat != 0){
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
