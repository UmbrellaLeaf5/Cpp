#include "button.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

Button::Button()
{
    setAcceptHoverEvents(true);
}

QRectF Button::boundingRect() const
{
    return QRectF(0,0,bWidth,bHeight);
}


void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
     QColor color;
    if(bHover==true){
       color =  QColor(200,0,0);
    }else{
        color =  QColor(255,255,255);
    }
    painter->setBrush(QBrush(color, Qt::SolidPattern));
    painter->drawRoundedRect(0,0,bWidth,bHeight,5,5);

   //color =  QColor(0,255,0);
   // painter->setBrush(QBrush(color, Qt::SolidPattern));
   // painter->drawRoundedRect(0,0,20,20,5,5);
    painter->drawText(QPointF(20, 20), "Umbrella Leaf");
}

void Button::setElmSize(int W, int H){
    bWidth = W;
    bHeight = H;
}


void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    bHover = true;
    QGraphicsItem::update();
}


void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    bHover = false;
    QGraphicsItem::update();

}

//Вызывается, когда нажата кнопка мыши, а указатель находился в пределах объекта
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    startMovePos = event->pos();
}

//Вызывается, когда отпущена нажатая ранее кнопка мыши
void Button::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

}
//Вызывается, когда мышка двигается находясь в пределах объекта
//Самая сложная функция в данной части примера.
void Button::mouseMoveEvent(QGraphicsSceneMouseEvent *event){

    //Если кнопка была нажата, нам нужно переместить объект за
    //мышкой. Чтобы понять, что пользователь действительно хочет
    //передвинуть объект, определяем разницу между старым и новым положением
    //мыши. Если оно больше 4 пикселей, перемещаеаем объект.
    int distance = (event->pos()-startMovePos).manhattanLength();
    if(distance > 4){

        //Для этого переводим глобальные координаты в координаты сцены
        QPointF ncoords = mapToScene(event->pos()-startMovePos);

        //Если указатель мыши не вышел за пределы ограниченной области, то перемещаем объект в новые координаты.
        this->setPos(ncoords);
        //Мы пока никак не ограничиваем пределы перемещения, об этом позже.
    }
}
