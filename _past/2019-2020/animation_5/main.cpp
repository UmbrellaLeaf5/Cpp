/* Анимация в Qt. Часть 5
 * Добавим перетаскивание кнопок(см. button.cpp)
 *
 * */
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
