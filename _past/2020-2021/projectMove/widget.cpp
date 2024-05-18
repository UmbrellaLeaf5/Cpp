#include "widget.h"
#include "ui_widget.h"
#include "myitem.h"
#include "cheese.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;

    ui->graphicsView->setScene(scene);  /// Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    /// Устанавливаем сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Отключаем скроллбар по горизонтали

    scene->setSceneRect(-250,-250,500,500); /// Устанавливаем область графической сцены

    scene->addLine(-250,0,250,0,QPen(Qt::black));   /// Добавляем горизонтальную линию через центр
    scene->addLine(0,-250,0,250,QPen(Qt::black));   /// Добавляем вертикальную линию через центр

    /* Дополнительно нарисуем органичение территории в графической сцене */
    scene->addLine(-250,-250, 250,-250, QPen(Qt::black));
    scene->addLine(-250, 250, 250, 250, QPen(Qt::black));
    scene->addLine(-250,-250,-250, 250, QPen(Qt::black));
    scene->addLine( 250,-250, 250, 250, QPen(Qt::black));

    MyItem *item1 = new MyItem;
    scene->addItem(item1);
    item1->setPos(0,0);

    connect(item1, SIGNAL(signalCheckCheese(QGraphicsItem *)),
            this, SLOT(deleteCheese(QGraphicsItem *)));

    Cheese *chees_1 = new Cheese;
    scene->addItem(chees_1);
    chees_1->setPos(100, 0);
    cheese.append(chees_1);

    Cheese *chees_2 = new Cheese;
    scene->addItem(chees_2);
    chees_2->setPos(-100, 0);
    cheese.append(chees_2);


    timer = new QTimer();
    connect(timer, &QTimer::timeout, item1, &MyItem::slotGameTimer);
    timer->start(1000 / 50);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::deleteCheese(QGraphicsItem *item)
{
    foreach(QGraphicsItem* chItem, cheese)
    {
        if (chItem == item)
        {
            scene -> removeItem(item);
            delete item;
        }
    }
    scene->removeItem(item);
    delete item;
}

