#ifndef GAMEVIEW_H
#define GAMEVIEW_H
/*  Естественно подключаем файл родительского класса */
#include <QGraphicsView>


/*Указываем, что будем наследовать свойства и методы класса QGraphicsView.
 * Подключите файл gameview.h в файле mainwindow.cpp, создадим экземпляр и
 * и добавим его в Ui(см. файл mainwindow.cpp).
 * Дальше переходите к Части 2.
*/
class gameView : public QGraphicsView
{
public:

    gameView();
};

#endif // GAMEVIEW_H
