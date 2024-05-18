#include "button.h"
#include <QPainter>

Button::Button()
{
    //Разрешаем фиксацию событий наведения
    setAcceptHoverEvents(true);
}

QRectF Button::boundingRect() const
{
    return QRectF(0,0,bWidth,bHeight);
}

//Рисуем белый или красный элемент, в зависимости от наведения указателя мыши
void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
     QColor color;
    if(bHover==true){
       color =  QColor(200,0,0);
    }else{
        color =  QColor(255,255,255);
    }
    painter->setBrush(QBrush(color, Qt::SolidPattern));
    painter->drawRoundedRect(0,0,bWidth,bHeight,5,5);
}

void Button::setElmSize(int W, int H){
    bWidth = W;
    bHeight = H;
}

//Если указатель мыши появился в пределах объекта, устанавливаем переменнюу bHover значение true
//и вызываем  update(). Это родительский метод, который вызовет перерисовку.
//ВАЖНОЕ ЗАМЕЧАНИЕ: операционная система, процессора и приложение знать не знает, что именно программист
//считает границами объекта. Для приложения границы объекта - это прямоуголная область в которую он вписан.
// Если вы скруглите углы ещё больше и попробуете навести указатель туда, где вроде бы "объекта нет".
// Событие наведение произойдёт. Здесь на помощью приходит геометрия. Но об этом отдельно.
void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    bHover = true;
    QGraphicsItem::update();
}

//Если указатель мыши вышел за пределы объекта, устанавливаем переменнюу bHover значение false
//и вызываем  update(). Это родительский метод, который вызовет перерисовку.
void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    bHover = false;
    QGraphicsItem::update();

}

//Переходите к части 5.
