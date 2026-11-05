#include "widget.h"
#include "ui_widget.h"
#include <QTabBar>
#include "stylehelper.h"
#include <QGraphicsPixmapItem>
#include <QDebug>
#include "defines.h"
#include <QPixmap>
#include <QGraphicsItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->Init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::startGame()
{
    inSlots[0] = false;
    inSlots[1] = false;
    inSlots[2] = false;
    this->showPlane();
    player = new Player;
    scene->addItem(player);
    player->setPos(0,-50);

    timer = new QTimer;
    timer->setInterval(1000/50);
    connect(timer, &QTimer::timeout,
            player, &Player::updateStatus);
    timer->start();
    ui->tabWidget->setCurrentIndex(1);

    keys.append(new Key);
    keys.last()->id = 1;
    keys.last()->setPos(-100,-100);
    scene->addItem(keys.last());

    keys.append(new Key);
    keys.last()->id = 2;
    keys.last()->setPos(100,-100);
    scene->addItem(keys.last());

    keys.append(new Key);
    keys.last()->id = 3;
    keys.last()->setPos(-200,-160);
    scene->addItem(keys.last());

    sword = new Sword;
    scene->addItem(sword);
    sword->setPos(50, -50);
    player->setZValue(1);



    connect(player,&Player::found,
            this, &Widget::checkKey);
    connect(player,&Player::numPressed,
            this, &Widget::updateSlots);
}

void Widget::help(){
    ui->tabWidget->setCurrentIndex(3);
    ui->textBrowser->setSource(QUrl("help.html"));
}
void Widget::settings(){
    ui->tabWidget->setCurrentIndex(2);
}

void Widget::gotoBack()
{
    ui->tabWidget->setCurrentIndex(0);
}

bool Widget::checkPlane(int y, int x)
{
    if(Plane[y][x] != CF){
        qDebug() << "FALSE";
        return false;
    }else{
        return true;
    }

}

void Widget::checkKey(QGraphicsItem *item)
{
    if(selectedSlot != -1){
         qDebug() << "select slot: "
                  << selectedSlot;
         for (int i=0;i<slotsItems.count();i++ ) {
             if(selectedSlot-1 ==slotsItems[i].num){
                 qDebug() << slotsItems[i].type;
                 scene->addItem(slotsItems[i].pointer);
                 slotsItems[i].pointer->setPos(0,0);
                 slotsItems.removeAt(i);
                 inSlots[i] = false;
             }
         }
    }

    foreach(Key* key, keys)
    {
        if(key == item){
            if(addKeyToSlot()){  
                slotItem si;
                si.type = "key";
                si.pointer = item;
                si.num = addSlot;
                slotsItems.append(si);
                this->scene->removeItem(item);
                keys.removeOne(key);
               // delete item ;


            }

        }
    }
    if(item == sword){
        if(addSwordToSlot()){
            slotItem si;
            si.type = "sword";
            si.pointer = item;
            si.num = addSlot;
            slotsItems.append(si);

            this->scene->removeItem(sword);
            //delete item;
        }
    }

}

void Widget::updateSlots(int num)
{
    ui->label->setStyleSheet(
    StyleHelper::getSlotStyle());
    ui->label_2->setStyleSheet(
    StyleHelper::getSlotStyle());
    ui->label_3->setStyleSheet(
    StyleHelper::getSlotStyle());

    switch (num) {
    case 1:
        ui->label->setStyleSheet(
        StyleHelper::getSelectSlotStyle());
        break;
    case 2:
        ui->label_2->setStyleSheet(
        StyleHelper::getSelectSlotStyle());
        break;
    case 3:
        ui->label_3->setStyleSheet(
        StyleHelper::getSelectSlotStyle());
        break;
    }
    selectedSlot = num;
}
void Widget::Init()
{
    QTabBar *tabbar = ui->tabWidget->
                      findChild<QTabBar *>();
    tabbar->hide();
    ui->tabWidget->setCurrentIndex(0);
    connect(ui->gameButton,
            &QPushButton::clicked,
            this,
            &Widget::startGame);
    connect(ui->settingsButton,
            &QPushButton::clicked,
            this,
            &Widget::settings);
    connect(ui->helpButton,
            &QPushButton::clicked,
            this,
            &Widget::help);
    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            &Widget::gotoBack);
    connect(ui->backHelpButton,
            &QPushButton::clicked,
            this,
            &Widget::gotoBack);
    ui->tabWidget->setStyleSheet(
        StyleHelper::getTabWidgetStyle());
    ui->gameButton->setStyleSheet(
        StyleHelper::getGameBtnStyle());
    ui->helpButton->setStyleSheet(
        StyleHelper::getGameBtnStyle());
    ui->settingsButton->setStyleSheet(
        StyleHelper::getGameBtnStyle());
    ui->tab->setStyleSheet(
        StyleHelper::getTabStyle());
    ui->label->setStyleSheet(
        StyleHelper::getSlotStyle());
    ui->label_3->setStyleSheet(
        StyleHelper::getSlotStyle());
    ui->label_2->setStyleSheet(
        StyleHelper::getSlotStyle());


    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(-300,-240,
                                   600,480);

}

void Widget::showPlane()
{
    int sX =-300, sY=-240;
    for(int y=0; y<5; y++){
        for(int x=0; x<10; x++){
            QPixmap *pix;
            switch (Plane[y][x]) {
            case CF:
                qDebug() << "пол";
                pix = new QPixmap(":/images/fl.png");
                break;
            case CWH:
                qDebug() << "гор.ст";
                pix = new QPixmap(":/images/wall_h.png");
                break;
            case CWV:
                qDebug() << "вер.ст";
                pix = new QPixmap(":/images/wall_v.png");
                break;
            case CDH:
                qDebug() << "гор.дв";
                pix = new QPixmap(":/images/door_h.png");
                break;
            case CDV:
                qDebug() << "верт.дв";
                pix = new QPixmap(":/images/door_v.png");
                break;
            }
            QGraphicsPixmapItem * item =
            new QGraphicsPixmapItem(*pix);
            scene->addItem(item);
            item->setPos(sX, sY);
            sX += 60;
        }
        sY += 60;
        sX = -300;
    }
}

bool Widget::addKeyToSlot()
{
    int index = -1;
    for (int i=0;i<3;i++ ) {
        if(inSlots[i]== false){
            index = i;
            inSlots[i] = true;
            itemsSlots[i] = "key";
            break;
        }
    }
    switch (index) {
    case 0:
        ui->label->setPixmap(
        QPixmap(":/images/key.png"));
        break;
    case 1:
        ui->label_2->setPixmap(
        QPixmap(":/images/key.png"));
        break;
    case 2:
        ui->label_3->setPixmap(
        QPixmap(":/images/key.png"));
        break;
    }
    if(index == -1)
        return false;
    else{
        addSlot = index;
        return true;
    }
}

bool Widget::addSwordToSlot()
{
    int index = -1;
    for (int i=0;i<3;i++ ) {
        if(inSlots[i]== false){
            index = i;
            inSlots[i] = true;
            itemsSlots[i] = "sword";
            break;
        }
    }
    switch (index) {
    case 0:
        ui->label->setPixmap(
        QPixmap(":/images/sword.png"));
        break;
    case 1:
        ui->label_2->setPixmap(
        QPixmap(":/images/sword.png"));
        break;
    case 2:
        ui->label_3->setPixmap(
        QPixmap(":/images/sword.png"));
        break;
    }
    if(index == -1)
        return false;
    else{
        addSlot = index;
        return true;
    }
}

