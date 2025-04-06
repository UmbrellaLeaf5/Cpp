#ifndef BUTTON_H
#define BUTTON_H
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class gameView;

class Button:public QGraphicsItem
{
public:
    Button(gameView * gameView);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setStatus(int S);
    int mX,mY;
    int num;
protected:
    void mousePressEvent(
       QGraphicsSceneMouseEvent *event) override;
private:
    int bWidth = 20;
    int bHeight = 20;
    int status = 1;
    gameView * graph;
};

#endif // BUTTON_H
