/* Анимация в Qt. Часть 2
 * Имеет смысл в момент инициализации нашего gameView установить некоторые
 * параметры. Посмотрите на файл gameview.h.
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
