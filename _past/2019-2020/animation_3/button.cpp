#include "button.h"
#include <QPainter>

Button::Button()
{

}

QRectF Button::boundingRect() const
{
    return QRectF(0,0,bWidth,bHeight);
}

//Функция paint производит отрисовку. Для этго в неё передаётся указатель на специальный объект
//painter (рисовальщик), с помощью которого и производится отрисовка.
void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    //Рисуем, собственно...
    painter->drawRoundedRect(0,0,bWidth,bHeight,5,5);
    //Добавление на сцену смотри в файле gameview.h
}
