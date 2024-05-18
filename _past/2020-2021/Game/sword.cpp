#include "sword.h"
#include <QPainter>

Sword::Sword(QObject *parent) : QObject(parent)
{

}

QRectF Sword::boundingRect() const
{
    return QRectF(-10,-30,20,45);
}

void Sword::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(
     QBrush(QColor(200,226,226)));
    QPointF points[4] ={
        {0,-20},
        {5,-15},
        {0,0},
        {-5,-15}};
    painter->drawPolygon(points,4);
    painter->drawRect(-5,-5,10,5);
    painter->setBrush(
     QBrush(QColor(100,50,50)));
    painter->drawRect(-2,0,4,6);
    painter->setBrush(
     QBrush(QColor(200,226,226)));
    painter->drawEllipse(-3,4,6,6);

}
