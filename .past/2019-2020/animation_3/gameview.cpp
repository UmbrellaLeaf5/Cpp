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

    //Устанавливаем координаты для btn
    btn.setPos(50,50);
    //Добавляем btn на сцену
    scene.addItem(&btn);

    //Переходим к части 4.
}
