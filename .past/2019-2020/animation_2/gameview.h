#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

/* Добавим объявление метода init_elements()
*/
class gameView : public QGraphicsView
{
public:

    gameView();
private:
    void init_elements();

    QGraphicsScene  scene;
};

#endif // GAMEVIEW_H
