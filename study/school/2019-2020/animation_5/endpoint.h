#ifndef ENDPOINT_H
#define ENDPOINT_H
#include <QGraphicsItem>

class EndPoint:public QGraphicsItem
{
public:

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    EndPoint();

private:
    int bWidth = 20;
    int bHeight = 20;

};

#endif // ENDPOINT_H
