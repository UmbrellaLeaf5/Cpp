#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

//Подключаем новый класс с кнопочкой Button
#include "button.h"


class gameView : public QGraphicsView
{
public:

    gameView();
private:
    void init_elements();

    QGraphicsScene  scene;

    //Объявляем переменную для кнопочки
    Button btn;

    /* Перейдите в файл реализации gameview.cpp*/

};

#endif // GAMEVIEW_H
