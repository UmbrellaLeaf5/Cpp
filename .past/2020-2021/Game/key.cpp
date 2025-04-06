#include "key.h"
#include <QPainter>

Key::Key(QObject *parent) : QObject(parent)
{

}

QRectF Key::boundingRect() const
{
    return QRectF(-15,-8,30,16);
}

void Key::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    QBrush brush(Qt::NoBrush);
    painter->setBrush(brush);
    QPen pen(Qt::yellow);
    pen.setWidth(4);
    painter->setPen(pen);
    painter->drawEllipse(-15,-8,16,16);

    pen = QPen(Qt::NoPen);
    brush = QBrush(Qt::yellow);
    painter->setBrush(brush);
    painter->setPen(pen);
    painter->drawRect(0,-3,16,6);
    painter->drawRect(6,3,8,5);


}
