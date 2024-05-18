#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "button.h"
#include <QVector>


class gameView : public QGraphicsView
{
public:
    gameView();
    void Hello(int x, int y);
private:
    void init_elements();
    QGraphicsScene  scene;
    Button *btn;
    Button *btn2;
    Button *btn3;
    Button *btn4;
    Button *btn5;
    int Matrix[20][20];
    void loadMatrix(int level);
    void showMatrix();
    QVector <Button *> btns;
    void updateButton(int x, int y, int bum);

};

#endif // GAMEVIEW_H
