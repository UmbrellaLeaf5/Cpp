/* Перемещение QGraphicsItem
 * 1. В дизайне добавляем QGraphicsView.
 * 2. Добавляем к нашему QGraphicsView графическую сцену, переменная
 * scene объявлена в файле mainwindow.h
 * Чтобы сцена не подстраивалась под координаты (не перемещалась),
 * задаём начальные координаты и размеры сцены.
 * А так же установим цвет фона сцены.
 * 3. В этом примере мы воспользуемся готовым QGraphicsItem
 * 4. Чтобы понять логику перемещния объекта, добавим кнопку и сделаем так,
 * чтобы нажание по ней приводило к перемещению объекта.
 *
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"


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


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qreal newX = rect->pos().x() + 5;
    qreal newY = rect->pos().y() + 2;
    rect->setPos(newX,newY);
}
