#include "myitem.h"

MyItem::MyItem()
{

}

QRectF MyItem::boundingRect() const
{
    return QRectF(-20, -20, 40, 40);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen (Qt::blue);
    pen.setWidth(2);
    painter->setPen(pen);
    QBrush brush(Qt::green);
    painter->setBrush(brush);
    painter->drawRect(-20, -20, 40, 40);
    painter->setBrush(QBrush(Qt::black));
    pen = QPen(Qt::black);
    pen.setWidth(1);
    painter->setPen(pen);
    painter->drawEllipse(-10, -10, 7, 7);
    painter->drawEllipse(4, -10, 7, 7);

    QPainterPath path(QPointF(-10, 5));
    path.cubicTo(-5, 10, 5, 10, 10, 5);
    painter->setBrush(Qt::NoBrush);
    painter->drawPath(path);
}
