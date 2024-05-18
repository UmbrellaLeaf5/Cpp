#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "key.h"
#include "sword.h"
#include <QTimer>
#include <QList>
#include <QVector>


class QGraphicsItem;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

struct slotItem{
    QString type;
    QGraphicsItem *pointer;
    int num;
};

struct Object{
    QString type;
    QGraphicsItem *item;
    int id;
    int slotNum = -1;
    bool inSlot = false;
    bool inScene = false;
    int x;
    int y;
    int local;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    bool checkPlane(int y, int x);
    bool checkDoor(int y, int x);


public slots:
    void checkKey(QGraphicsItem* item);
    void updateSlots(int num);

private slots:
    void startGame();
    void help();
    void settings();
    void gotoBack();
    void doorEnter();
    void changeLevel();
    void changeLevelToStart();


private:
    Ui::Widget *ui;
    void Init();
    QGraphicsScene *scene;
    void showPlane();
    Player * player;
    QTimer *timer;
    QList <Key*> keys;
    bool addKeyToSlot();
    bool addSwordToSlot();
    bool inSlots[3];
    QString itemsSlots[3];
    int select = 0;
    Sword * sword;
    QVector <slotItem> slotsItems;
    int selectedSlot = -1;
    int addSlot;
    void openDoor(int x, int y);
    QVector <Object> gameObjects;
    void clearSlot(int num);

};
#endif // WIDGET_H
