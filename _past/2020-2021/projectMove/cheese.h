#ifndef CHEESE_H
#define CHEESE_H

#include <QObject>
#include <QGraphicsItem>

class Cheese : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Cheese(QObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

signals:
    void signalCheckCheese(QGraphicsItem *item);

};

#endif // CHEESE_H
