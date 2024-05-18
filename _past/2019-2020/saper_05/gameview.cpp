#include "gameview.h"
#include "time.h"
#include "QDebug"

gameView::gameView()
{

    setRenderHint(QPainter::Antialiasing);
    setCacheMode(QGraphicsView::CacheNone);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFrameStyle(0);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    setScene(&scene);
    setSceneRect(0,0,420,420);

   //Добавляем элементы
    init_elements();

}
void gameView::Hello(int x, int y)
{
    qDebug() << "Kletka" << y << ":" << x << " najata" << endl;
    if (Matrix[y][x] == -1)
    {
        qDebug() << "Boom!";
    }
    else
    {
        int bum = 0;
        if(y > 0)
        {
            if(Matrix[y-1][x] == -1)
                bum += 1;

            if (x > 0)
            {
                if(Matrix[y-1][x-1] == -1)
                    bum += 1;
            }
            if (x < 19)
            {
                if(Matrix[y-1][x+1] == -1)
                    bum += 1;
            }


        }

        if(y < 19)
        {
            if(Matrix[y+1][x] == -1)
                bum += 1;
            if (x > 0)
            {
                if(Matrix[y+1][x-1] == -1)
                    bum += 1;
            }
            if (x < 19)
            {
                if(Matrix[y+1][x+1] == -1)
                    bum += 1;
            }
        }

        if(x > 0)
        {
            if(Matrix[y][x-1] == -1)
                bum += 1;
        }
        if(x < 19)
        {
            if(Matrix[y][x+1] == -1)
                bum += 1;
        }
        qDebug() << "Itogo: " << bum << endl;
        updateButton(x,y,bum);
    }
}

void gameView::init_elements()
{
    loadMatrix(1);
    showMatrix();


}

void gameView::loadMatrix(int level)
{
    srand(time(NULL));
    int RX,RY;
    if(level==1){
        for (int i=0;i<20;i++) {
            RX = rand()%20;
            RY = rand()%20;
            if(Matrix[RY][RX] != -1){
               Matrix[RY][RX] = -1;
            }else{
               i--;
            }
        }

    }
}

void gameView::showMatrix()
{
    int cY = 0;
    int cX = 0;
    for (int y=0;y<20;y++) {
        for (int x=0;x<20;x++) {
            Button *item = new Button(this);
            if(Matrix[y][x]==-1){
                item->setStatus(4);
            }
            scene.addItem(item);
            cX = x*21;
            cY = y*21;
            item->setPos(cX,cY);
            item->mX = x;
            item->mY = y;
            btns.append(item);

        }
    }
}
void gameView::updateButton(int x, int y, int bum)
{
    for(int i = 0; i < btns.count(); i ++)
    {
        if((btns.at(i) -> mX == x)&&
                (btns.at(i) -> mY == y))
        {
            btns.at(i) -> num = bum;
            btns.at(i) -> setStatus(3);
            btns.at(i) -> update();
        }
    }
}
