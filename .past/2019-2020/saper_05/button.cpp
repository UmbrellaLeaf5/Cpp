#include "button.h"
#include <QPainter>
#include <QDebug>
#include "gameview.h"
Button::Button(gameView *gameView)
    : graph(gameView)
{

}

QRectF Button::boundingRect() const
{
    return QRectF(0,0,bWidth,bHeight);
}
void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    painter->setPen(Qt::PenStyle::NoPen);
    QBrush brush;
    QColor color;
    color = QColor(100,100,100);
    if(status == 1){
       color = QColor(200,200,200);
    }else if(status == 2){
        color = QColor(100,100,100);
    }else if(status==4){
         color = QColor(100,100,100);
    }else if(status==5){
         color = QColor(200,200,200);
    }
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    painter->setBrush(brush);
    painter->drawRect(0,0,bWidth,bHeight);
    if(status==5){

        painter->drawPixmap(0,0,20,20,
               QPixmap(":/pix/flag.png"));
    }
    if(status == 4){
        color = QColor(255,50,50);
        brush.setColor(color);
        painter->setBrush(brush);
        painter->drawEllipse(5,5,10,10);
    }
    if(status == 3){
        QFont font = painter->font();
        painter->setPen(QColor(255,255,255));
        font.setPixelSize(14);
        painter->setFont(font);
        painter->drawText(5,15,QString::number(num));
    }

}

void Button::setStatus(int S)
{
    status = S;
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   // qDebug() << mY << ":" << mX;
   //mousePressEvent(event);
    graph->Hello(mX, mY);
}
