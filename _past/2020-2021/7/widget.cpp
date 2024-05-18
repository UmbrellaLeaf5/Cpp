#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "myitem.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(-300, -200, 600, 400);
    QPen pen(QColor(100, 100, 100));
    pen.setWidth(5);
    QBrush brush(Qt::red);
    scene->addRect(0, 0, 40, 40, pen, brush);
    QGraphicsRectItem *rect = new QGraphicsRectItem(200, 200, 40, 40);
    scene->addItem(rect);
    myitem = new MyItem;
    scene->addItem(myitem);
    myitem->setPos(-100, -100);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    myitem->setPos(myitem->pos().x()+5, myitem->pos().y());
}
