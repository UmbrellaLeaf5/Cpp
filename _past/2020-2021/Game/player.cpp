#include "player.h"
#include <QPainter>
#include <QPixmap>
#include <windows.h>
#include <QDebug>
#include "widget.h"
Player::Player(QObject *parent) : QObject(parent)
{

}

QRectF Player::boundingRect() const
{
    return QRectF(-14,-17,27,33);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch (status) {
    case 0:
        if(vector==1){
            painter->drawImage(-14,-17,
            QImage(":/images/12.png"));
        }else if(vector==2){
            painter->drawImage(-14,-17,
            QImage(":/images/22.png"));
        }else if(vector==3){
            painter->drawImage(-14,-17,
            QImage(":/images/31.png"));
        }else if(vector==4){
            painter->drawImage(-14,-17,
            QImage(":/images/42.png"));
        }
        break;
    case 1:
        if(step == 0){
            painter->drawImage(-14,-17,
            QImage(":/images/12.png"));
        }
        if(step == 1){
            painter->drawImage(-14,-17,
            QImage(":/images/11.png"));
        }
        if(step == 2){
            painter->drawImage(-14,-17,
            QImage(":/images/12.png"));
        }
        if(step == 3){
            painter->drawImage(-14,-17,
            QImage(":/images/13.png"));
        }
        break;
    case 2:
        if(step == 0){
            painter->drawImage(-14,-17,
            QImage(":/images/22.png"));
        }
        if(step == 1){
            painter->drawImage(-14,-17,
            QImage(":/images/21.png"));
        }
        if(step == 2){
            painter->drawImage(-14,-17,
            QImage(":/images/22.png"));
        }
        if(step == 3){
            painter->drawImage(-14,-17,
            QImage(":/images/23.png"));
        }
        break;
    case 3:
        if(step == 0){
            painter->drawImage(-14,-17,
            QImage(":/images/32.png"));
        }
        if(step == 1){
            painter->drawImage(-14,-17,
            QImage(":/images/31.png"));
        }
        if(step == 2){
            painter->drawImage(-14,-17,
            QImage(":/images/32.png"));
        }
        if(step == 3){
            painter->drawImage(-14,-17,
            QImage(":/images/33.png"));
        }
        break;
    case 4:
        if(step == 0){
            painter->drawImage(-14,-17,
            QImage(":/images/42.png"));
        }
        if(step == 1){
            painter->drawImage(-14,-17,
            QImage(":/images/41.png"));
        }
        if(step == 2){
            painter->drawImage(-14,-17,
            QImage(":/images/42.png"));
        }
        if(step == 3){
            painter->drawImage(-14,-17,
            QImage(":/images/43.png"));
        }
        break;
    }
}

void Player::updateStatus()
{
    if(GetAsyncKeyState(VK_LEFT)){
        status = 2;
        vector = 2;
    }else if(GetAsyncKeyState(VK_RIGHT)){
        status = 3;
        vector = 3;
    }else if(GetAsyncKeyState(VK_DOWN)){
        status = 1;
        vector = 1;
    }else if(GetAsyncKeyState(VK_UP)){
        status = 4;
        vector = 4;
    }else if(GetAsyncKeyState(VK_F1)){
        emit numPressed(1);
    }else if(GetAsyncKeyState(VK_F2)){
        emit numPressed(2);
    }else if(GetAsyncKeyState(VK_F3)){
        emit numPressed(3);
    }else if(GetAsyncKeyState(VK_SPACE)){

        QList <QGraphicsItem*> gItems =
         this->scene()->items(
         QRectF(mapToScene(-14,-17),
                mapToScene(27,33))
         );

        foreach(QGraphicsItem *item, gItems)
        {
            if(item == this) continue;
            emit found(item);
        }
    }else{
        status = 0;
    }
    counter ++;
    if(counter==6){
        step ++;
        counter = 0;
    }
    if(step == 4){
        step = 0;
    }
    if((counter == 0)&&(status != 0)){
        switch(vector){
        case 1:
            setPos(mapToParent(0,10));
            break;
        case 2:
            setPos(mapToParent(-10,0));
            break;
        case 3:
            setPos(mapToParent(10,0));
            break;
        case 4:
            setPos(mapToParent(0,-10));
            break;
        }
        int cY, cX;
        if((vector == 2)||(vector==4)){
            cX= (pos().x() + 300-14)/60;
            cY= (pos().y() + 240-17)/60;
            if(!parentWidg->checkPlane(cY,cX)){
                if(vector == 2){
                    setPos(mapToParent(10,0));
                }else if(vector == 4){
                    setPos(mapToParent(0,10));
                }
            }
        }else{
            cX= (pos().x() + 300+13)/60;
            cY= (pos().y() + 240+16)/60;
            if(!parentWidg->checkPlane(cY,cX)){
                if(vector == 1){
                    setPos(mapToParent(0,-10));
                }else if(vector == 3){
                    setPos(mapToParent(-10,0));
                }
            }
        }
        qDebug() << cY << ":" << cX;
    }
    this->update();
}

void Player::setParent(Widget *parent)
{
    this->parentWidg = parent;
}
