#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>
#include <QObject>

class MyItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    MyItem(QObject *parent = 0);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

public slots:
    void slotGameTimer();
signals:
    void signalCheckCheese(QGraphicsItem *item);
private:
    qreal angle;
};

#endif // MYITEM_H
