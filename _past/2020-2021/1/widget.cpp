#include "widget.h"
#include "QDebug"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(0, 0, 400, 400);
    button = new QPushButton(this);
    button -> setText ("Button");
    qDebug() << "Привет!";
    connect(button, SIGNAL(cliced), this, SLOT(hello));
}

void Widget::hello()
{
    qDebug() << "hello!";
}
Widget::~Widget()
{

}

