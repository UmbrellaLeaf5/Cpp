#ifndef KEY_H
#define KEY_H
#include <QObject>
#include <QGraphicsItem>

class Key : public QObject,
        public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Key(QObject *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    int id;
signals:

};

#endif // KEY_H
