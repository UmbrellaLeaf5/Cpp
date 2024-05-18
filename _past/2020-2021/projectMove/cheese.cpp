#include "cheese.h"
#include <QPainter>

Cheese::Cheese(QObject *parent) : QObject(parent),
    QGraphicsItem()
{

}

QRectF Cheese::boundingRect() const
{
    return QRectF(-20, -25, 40, 50);
}

void Cheese::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPainterPath path(QPointF(-20, 15));
    path.cubicTo(-10, 25, 10, 25, 20, 15);
    path.cubicTo(20, 15, 0, -25, 0, -25);
    path.cubicTo(0, -25, -20, 15, -20, 15);
    painter->setBrush(QColor(250, 200, 0));
    painter->drawPath(path);
    painter->setBrush(QColor(230, 100, 0));
    painter->setPen(QColor(230, 100, 0));
    painter->drawEllipse(QPoint(5,5), 5, 5);

    QPainterPath path2(QPointF(-5, -15));
    path2.cubicTo(5, -11, 0, 1, -10, -5);
    painter->drawPath(path2);
}
