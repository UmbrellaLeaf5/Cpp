#ifndef BUTTON_H
#define BUTTON_H
#include <QGraphicsItem>

/* Класс будет наследоваться от QGraphicsItem и нам нужно переопределить два метода,
которые отвечают за отрисовку. Это позволит на перерисовывать экземпляры данного
объекта.
Ключевое слово  overкide помогает избежать ошибки и правильно обработать переопределённые функции,
но об этом как-нибудь отдельно. Пока просто используем их "бездумно".
boundingRect() используется для возврата данных о том, какой участок нужно перерисовать,
а paint отвечает за саму перерисовку.
Кроме этого, добавим переменные для ширины и высоты элемента. Посмотрите на реализацию (button.h)
 */

class Button:public QGraphicsItem
{
public:
    Button();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int bWidth = 50;
    int bHeight = 50;
};

#endif // BUTTON_H
