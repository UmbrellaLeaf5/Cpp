#ifndef BUTTON_H
#define BUTTON_H
#include <QGraphicsItem>



class Button:public QGraphicsItem
{
public:
    Button();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setElmSize(int W, int H);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
private:
    int bWidth = 0;
    int bHeight = 0;
    bool bHover = false;

    //Координаты, где была нажата кнопка мыши
    QPointF startMovePos;

};

#endif // BUTTON_H
