/* Перемещение QGraphicsItem. Часть 2
 * Теперь попробуем сделать так, чтобы движение происходило автоматически
 * 4. Добавим таймер (его объявление в файле mainwindow.h)
 * Установим интервал вызова 1/30 секунды
 * Таймер написан так, что в момент срабатывания он "выкидывает" сигнал timeout,
 * поэтому мы можем связать этот сигнал с функцийе updatePosition, которую
 * придумали сами. Получается, что она будет вызываться 30 раз за одну секунду.
 * В ней мы просто меняем позицию элемента.
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

    //4
    timer = new QTimer;
    timer ->setInterval(1000/30);
    connect(timer,SIGNAL(timeout()),this,SLOT(updatePosition()));
    timer->start();


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
}
