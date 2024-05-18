#include "gameview.h"


gameView::gameView()
{
    //В конструкторе добавим сглаживание для нарисованных нами фигур
    setRenderHint(QPainter::Antialiasing);

    //Не даём кешировать содержимое нашего виджета. Кэш - это отдельная тема,
    //с которой имеет смысл разобраться позже.
    setCacheMode(QGraphicsView::CacheNone);

    //Запрещаем показывать скрол бар
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Устанавливаем нулевые отступы (хотя это не совсем отступы, но пока можно сказать так)
    setFrameStyle(0);

    //А так же... запретим индексацию элементов сцены (это позволит нам избавиться от дополнительных,
    //действий ускоряющих обнаружение элементов, которые имеют смысл для сцен без анимации).
    //Переменную scene мы создали в заголовочном файле gameview.h
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    //Устанавливаем сцену для нашего gameView, передав туда ссылку на созданную нами scene.
    setScene(&scene);

   //Далее переходите к части 3.


}
void gameView::init_elements(){

}
