/* Анимация в Qt. Часть 3
 * Добавим класс для некоторых графических элементов нашей сцены, назовоём его Button
 * создадим соответсвенно класс. Перейдите в файл button.h
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
