#include "gameview.h"


gameView::gameView()
{

    setRenderHint(QPainter::Antialiasing);
    setCacheMode(QGraphicsView::CacheNone);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFrameStyle(0);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    setScene(&scene);

   //Добавляем элементы
    init_elements();

}


void gameView::init_elements(){


    btn.setPos(50,50);
    btn.setElmSize(100,50);
    scene.addItem(&btn);

}
