#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QList>
#include <QGraphicsScene>

class Widget;

class Player : public QObject,
        public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
signals:
    void found(QGraphicsItem *);
    void numPressed(int);
public slots:
    void updateStatus();
    void setParent(Widget *parent);
private:
    int step = 0;
    int counter = 0;
    int status = 4; //1 вниз, 2 влево,
                    //3 вправо, 4 вверх
    int vector = 4;
    Widget * parentWidg;

};

#endif // PLAYER_H
