#include "widget.h"
#include "QDebug"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    setGeometry(0, 0, 400, 400);
    //Объявление кнопок
    b_1 = new QPushButton(this);
    b_2 = new QPushButton(this);
    b_3 = new QPushButton(this);

    b_4 = new QPushButton(this);
    b_5 = new QPushButton(this);
    b_6 = new QPushButton(this);

    b_7 = new QPushButton(this);
    b_8 = new QPushButton(this);
    b_9 = new QPushButton(this);

    b_0 = new QPushButton(this);

    b_plus = new QPushButton(this);
    b_minus = new QPushButton(this);
    b_res = new QPushButton(this);
    b_clear = new QPushButton(this);

    //Объявление текстового поля
    edit = new QLineEdit(this);

    //Объявление местоположения текстового поля
    edit->setGeometry(10, 10, 380, 30);

    //Объявление местоположения кнопок
    b_1->setGeometry(10, 50, 75, 75);
    b_2->setGeometry(90, 50, 75, 75);
    b_3->setGeometry(170, 50, 75, 75);

    b_4->setGeometry(10, 130, 75, 75);
    b_5->setGeometry(90, 130, 75, 75);
    b_6->setGeometry(170, 130, 75, 75);

    b_7->setGeometry(10, 210, 75, 75);
    b_8->setGeometry(90, 210, 75, 75);
    b_9->setGeometry(170, 210, 75, 75);

    b_0->setGeometry(90, 290, 75, 75);

    b_plus->setGeometry(10, 290, 75, 75);
    b_minus->setGeometry(170, 290, 75, 75);
    b_res->setGeometry(250, 130, 75, 75);
    b_clear->setGeometry(250, 50, 75, 75);

    //Объявление текста кнопок
    b_1 -> setText (" 1 ");
    b_2 -> setText (" 2 ");
    b_3 -> setText (" 3 ");

    b_4 -> setText (" 4 ");
    b_5 -> setText (" 5 ");
    b_6 -> setText (" 6 ");

    b_7 -> setText (" 7 ");
    b_8 -> setText (" 8 ");
    b_9 -> setText (" 9 ");

    b_0 -> setText (" 0 ");

    b_plus -> setText (" + ");
    b_minus -> setText (" - ");
    b_res -> setText (" = ");
    b_clear -> setText (" C ");

    //Присоеденение кнопок
    connect(b_1, SIGNAL(clicked()), this, SLOT(pressKey()));

    connect(b_clear, SIGNAL(clicked()), this, SLOT(cesarRes()));
    edit->setText("0");

}

void Widget::cesarRes()
{
    edit->setText("0");
}
void Widget::pressKey()
{
    QString str = edit->text();
    if (str == "0")
    {
        str = "";
    }
    str += "1";
    edit->setText(str);
}
Widget::~Widget()
{

}
