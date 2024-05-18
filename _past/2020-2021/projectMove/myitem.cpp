#include "myitem.h"
#include <QDebug>

#include <QGraphicsScene>
#include <QPainter>
#include <QRandomGenerator>
#include <QStyleOption>
#include <QtMath>

#include "windows.h"

MyItem::MyItem(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    angle = 0;     // Задаём угол поворота графического объекта
    setRotation(angle);
}

QRectF MyItem::boundingRect() const
{
     return QRectF(-25,-40,50,80);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /* QPolygon polygon;   /// Используем класс полигона, чтобы отрисовать треугольник
           /// Помещаем координаты точек в полигональную модель
           polygon << QPoint(0,-40) << QPoint(25,40) << QPoint(-25,40);
           painter->setBrush(Qt::red);     /// Устанавливаем кисть, которой будем отрисовывать объект
           painter->drawPolygon(polygon);  /// Рисуем треугольник по полигональной модели
           Q_UNUSED(option);
           Q_UNUSED(widget); */
    painter->setBrush(QColor(192, 192, 192));
    painter->drawEllipse(-10, -22, 20, 44);

    painter->setBrush(QColor(50, 50, 50));
    painter->drawEllipse(-10, -17, 8, 8);
    painter->drawEllipse(2, -17, 8, 8);

    painter->setBrush(QColor(50, 50, 50));
    painter->drawEllipse(-8, -17, 8, 8);
    painter->drawEllipse(4, -17, 8, 8);

    painter->drawEllipse(QRectF(-2, -22, 4, 4));

    painter->setBrush(QColor(200, 200, 200));
    painter->drawEllipse(-17, -12, 16, 16);
    painter->drawEllipse(1, -12, 16, 16);

    QPainterPath path(QPointF (0, 22));
    path.cubicTo(-5, 24, -5, 24, 0, 27);
    path.cubicTo(5, 29, 5, 34, 0, 30);
    path.cubicTo(-5, 34, -5, 44, 0, 37);
    painter->setBrush(Qt::NoBrush);
    painter->drawPath(path);
}

void MyItem::slotGameTimer()
{

    /* Поочерёдно выполняем проверку на нажатие клавиш
         * с помощью функции асинхронного получения состояния клавиш,
         * которая предоставляется WinAPI
         * */
        if(GetAsyncKeyState(VK_LEFT)){
            angle -= 10;        // Задаём поворот на 10 градусов влево
            setRotation(angle); // Поворачиваем объект
        }
        if(GetAsyncKeyState(VK_RIGHT)){
            angle += 10;        // Задаём поворот на 10 градусов вправо
            setRotation(angle); // Поворачиваем объект
        }
        if(GetAsyncKeyState(VK_UP)){
            setPos(mapToParent(0, -5));     /* Продвигаем объект на 5 пискселей вперёд
                                             * перетранслировав их в координатную систему
                                             * графической сцены
                                             * */
        }
        if(GetAsyncKeyState(VK_DOWN)){
            setPos(mapToParent(0, 5));      /* Продвигаем объект на 5 пискселей назад
                                             * перетранслировав их в координатную систему
                                             * графической сцены
                                             * */
        }

        /* Проверка выхода за границы поля
         * Если объект выходит за заданные границы, то возвращаем его назад
         * */
        if(this->x() - 10 < -250){
            this->setX(-240);       // слева
        }
        if(this->x() + 10 > 250){
            this->setX(240);        // справа
        }

        if(this->y() - 10 < -250){
            this->setY(-240);       // сверху
        }
        if(this->y() + 10 > 250){
            this->setY(240);        // снизу
        }
        QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF()
                                                               << mapToScene(0, 0)
                                                               << mapToScene(-15, -18)
                                                               << mapToScene(15, -18));
        for(int i = 0; i < foundItems.count(); i++)
        {
            if(foundItems[i] == this)
            {
                continue;

            }
             emit signalCheckCheese(foundItems[i]);
        }
}



