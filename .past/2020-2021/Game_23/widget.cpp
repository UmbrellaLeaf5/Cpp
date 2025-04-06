#include "widget.h"
#include "ui_widget.h"
#include <QTabBar>
#include "stylehelper.h"
#include <QGraphicsPixmapItem>
#include <QDebug>
#include "defines.h"
#include <QPixmap>
#include <QGraphicsItem>
#include <QFile>

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

    //Новое-----------------------
    Key* key1 = new Key;
    gameObjects.append(Object());
    gameObjects.last().id = 1;
    gameObjects.last().inScene = true;
    gameObjects.last().item = key1;
    gameObjects.last().type = "key";
    gameObjects.last().item->setPos(-100,-100);
    scene->addItem(key1);

    Key* key2 = new Key;
    gameObjects.append(Object());
    gameObjects.last().id = 2;
    gameObjects.last().inScene = true;
    gameObjects.last().item = key2;
    gameObjects.last().type = "key";
    gameObjects.last().item->setPos(200,-100);
    scene->addItem(key2);

    Key* key3 = new Key;
    gameObjects.append(Object());
    gameObjects.last().id = 3;
    gameObjects.last().inScene = true;
    gameObjects.last().item = key3;
    gameObjects.last().type = "key";
    gameObjects.last().item->setPos(-200,-160);
    scene->addItem(key3);

    sword = new Sword;
    gameObjects.append(Object());
    gameObjects.last().id = 4;
    gameObjects.last().inScene = true;
    gameObjects.last().item = sword;
    gameObjects.last().type = "sword";
    scene->addItem(sword);
    sword->setPos(50, -50);

    player->setZValue(1);



    connect(player,&Player::found,
            this, &Widget::checkKey);
    connect(player,&Player::numPressed,
            this, &Widget::updateSlots);
    connect(player,&Player::enterDoor,
            this, &Widget::doorEnter);
    connect(player,&Player::topBorder,
            this, &Widget::changeLevel);
    connect(player,&Player::bottomBorder,
            this, &Widget::changeLevelToStart);
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

void Widget::doorEnter()
{
    qDebug() << "doorEndter";
    if(selectedSlot != -1){
        if(player->door){
            qDebug() << "Проверить ключ";
            for (int i=0;i<gameObjects.count();i++) {
                if(selectedSlot-1 ==gameObjects[i].slotNum){
                    if(gameObjects[i].type == "key"){
                        qDebug() << "Ключ в слоте";
                        this->clearSlot(selectedSlot);
                        int y = player->doorY;
                        int x = player->doorX;
                        Plane[y][x] = CF;
                        int sX =-300 + x*60;
                        int sY=-240 + y*60;
                        QPixmap *pix = new QPixmap(":/images/fl.png");
                        QGraphicsPixmapItem * item =
                        new QGraphicsPixmapItem(*pix);
                        scene->addItem(item);
                        item->setPos(sX, sY);
                    }
                }
            }

        }
    }
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

bool Widget::checkDoor(int y, int x)
{
    if((Plane[y][x] != CDV) && (Plane[y][x] != CDH)){
        return false;
    }else{
        return true;
    }
}

void Widget::checkKey(QGraphicsItem *item)
{
    /*
    if(selectedSlot != -1){
         qDebug() << "select slot: "
                  << selectedSlot;
         for (int i=0;i<slotsItems.count();i++ ) {
             if(selectedSlot-1 ==slotsItems[i].num){
                 qDebug() << slotsItems[i].type;
                 scene->addItem(slotsItems[i].pointer);
                 slotsItems[i].pointer->setPos(
                 player->pos().x(),
                 player->pos().y()+30);
                 slotsItems.removeAt(i);
                 selectedSlot  = -1;
                 qDebug() << "num " <<slotsItems[i].num;
                 if(slotsItems[i].num == 1){
                     ui->label->clear();
                     inSlots[0] = false;
                 }else if(slotsItems[i].num == 2){
                     ui->label_2->clear();
                     inSlots[1] = false;
                 }else if(slotsItems[i].num == 3){
                     ui->label_3->clear();
                     inSlots[2] = false;
                 }

                 ui->label->setStyleSheet(
                 StyleHelper::getSlotStyle());
                 ui->label_2->setStyleSheet(
                 StyleHelper::getSlotStyle());
                 ui->label_3->setStyleSheet(
                 StyleHelper::getSlotStyle());
                 break;

             }
         }
    }
    */

    if(selectedSlot != -1){
          qDebug() << "Select slot:" << selectedSlot;
         for (int i=0;i<gameObjects.count();i++ ) {
             if(selectedSlot-1 ==gameObjects[i].slotNum){
                qDebug() << "Select slot: " << selectedSlot
                         << " obj: " << gameObjects[i].slotNum;
                scene->addItem(gameObjects[i].item);
                gameObjects[i].item->setPos(
                player->pos().x(),
                player->pos().y()+30);
                gameObjects[i].slotNum = -1;
                gameObjects[i].inScene = true;
                gameObjects[i].inSlot = false;

                this->clearSlot(selectedSlot);
                break;
             }
         }
    }else{
        qDebug() << "No selected slot:" << selectedSlot;
    }
    for(int i=0;i<gameObjects.count();i++){

        if(gameObjects[i].item == item){
            if(gameObjects[i].type == "key"){
                if(addKeyToSlot()){
                    gameObjects[i].inSlot = true;
                    gameObjects[i].inScene = false;
                    gameObjects[i].slotNum = addSlot;
                    this->scene->removeItem(item);
                }
            }else if(gameObjects[i].type == "sword"){
                if(addSwordToSlot()){
                    gameObjects[i].inSlot = true;
                    gameObjects[i].inScene = false;
                    gameObjects[i].slotNum = addSlot;
                    this->scene->removeItem(item);
                }
            }
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

void Widget::openDoor(int x, int y)
{
    Plane[y][x] = CF;
}

void Widget::clearSlot(int num)
{
    if(num == 1){
        ui->label->clear();
        inSlots[0] = false;
    }else if(num == 2){
        ui->label_2->clear();
        inSlots[1] = false;
    }else if(num == 3){
        ui->label_3->clear();
        inSlots[2] = false;
    }
    selectedSlot  = -1;
    ui->label->setStyleSheet(
    StyleHelper::getSlotStyle());
    ui->label_2->setStyleSheet(
    StyleHelper::getSlotStyle());
    ui->label_3->setStyleSheet(
                StyleHelper::getSlotStyle());
}

void Widget::changeLevel()
{
    QFile file0("level1.txt");
    if(file0.open(QIODevice::Text|QIODevice::WriteOnly))
    {
        QString res = "";
        for(int y = 0; y < 5; y++)
        {
            for(int x = 0; x < 10; x++)
            {
                res += QString::number(Plane[y][x]);
            }
            res += "\n";
        }
        file0.write(res.toUtf8());
        file0.close();
    }
    QFile file("level2.txt");
    if(file.open(QIODevice::Text|QIODevice::ReadOnly)){
        int y = -1;
        while (!file.atEnd()) {
            QString line= file.readLine().trimmed();
            y++;
            for(int i=0; i<line.length();i++){
                int N = QString(line[i]).toInt();
                qDebug() << "P["<< y <<"]"
                         << "[" << i << "]="
                         << N;
                Plane[y][i] = CellsTypes(N);

            }

        }
    }

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
    player->setPos(player->pos().x(), 30);
    for(int i = 0; i < gameObjects.count(); i++)
    {
        QGraphicsItem * item = gameObjects.at(i).item;
        if(gameObjects.at(i).inScene)
        {
            scene->removeItem(item);
            gameObjects[i].inScene = false;
        }
    }

}

void Widget::changeLevelToStart()
{
    qDebug() << "BottomBorder_TRUE";
}

