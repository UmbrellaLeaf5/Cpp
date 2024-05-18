#ifndef BUTTON_H
#define BUTTON_H
#include <QGraphicsItem>

/* Добавим метод, который будет управляь размерами нашего элемента
 * setElmSize(). Посмотрите реализацию и использование этого метода (button.h и  gameview.cpp).
 * Так же добавим реакцию кнопки на наведение мышки. Для этого переопределим два метода родительского
 * класса: hoverEnterEvent()и hoverLeaveEvent(). А так же добавить переменную,
 * которая будет хранить состояние кнопки. Перейдите в файл реализации button.h
 */

class Button:public QGraphicsItem
{
public:
    Button();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setElmSize(int W, int H);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
private:
    int bWidth = 0;
    int bHeight = 0;
    bool bHover = false;

};

#endif // BUTTON_H
