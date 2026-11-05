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

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    bool checkPlane(int y, int x);

public slots:
    void checkKey(QGraphicsItem* item);
    void updateSlots(int num);
private slots:
    void startGame();
    void help();
    void settings();
    void gotoBack();


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
    //void changeItems();
    bool inSlots[3];
    QString itemsSlots[3];
    int select = 0;
    Sword * sword;
    QVector <slotItem> slotsItems;
    int selectedSlot = -1;
};
#endif // WIDGET_H
