#ifndef SWORD_H
#define SWORD_H

#include <QObject>
#include <QGraphicsItem>

class Sword : public QObject,
        public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Sword(QObject *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
signals:

};

#endif // SWORD_H
