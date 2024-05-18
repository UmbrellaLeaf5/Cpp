#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWinStyle();
    setButton();
    edit = new QLineEdit(this);
    edit->setGeometry(30, 10, 445, 80);
    N1 = 0;
    N2 = 0;
    buf = "";
    Z = "";

}

Widget::~Widget()
{

}

void Widget::setWinStyle()
{
    setFixedWidth(500);
    setFixedHeight(500);
    setWindowTitle("Calculator");
}

void Widget::setButton()
{
    b_1 = new QPushButton(this);
    b_2 = new QPushButton(this);
    b_3 = new QPushButton(this);
    b_plus = new QPushButton(this);

    b_4 = new QPushButton(this);
    b_5 = new QPushButton(this);
    b_6 = new QPushButton(this);
    b_minus = new QPushButton(this);

    b_7 = new QPushButton(this);
    b_8 = new QPushButton(this);
    b_9 = new QPushButton(this);
    b_div = new QPushButton(this);

    b_0 = new QPushButton(this);
    b_mult = new QPushButton(this);
    b_clear = new QPushButton(this);
    b_eq = new QPushButton(this);


    addButton(b_1, 1, 1, "1");
    addButton(b_2, 2, 1, "2");
    addButton(b_3, 3, 1, "3");
    addButton(b_plus, 4, 1, "+");

    addButton(b_4, 1, 2, "4");
    addButton(b_5, 2, 2, "5");
    addButton(b_6, 3, 2, "6");
    addButton(b_minus, 4, 2, "-");

    addButton(b_7, 1, 3, "7");
    addButton(b_8, 2, 3, "8");
    addButton(b_9, 3, 3, "9");
    addButton(b_div, 4, 3, "/");

    addButton(b_0, 1, 4, "0");
    addButton(b_mult, 2, 4, "*");
    //addButton(b_clear, 3, 4, "C");
    addButton(b_eq, 4, 4, "=");

    b_clear->setGeometry(260, 370, 100, 75);
    b_clear->setText("C");
    connect(b_clear, SIGNAL(clicked()), this, SLOT(cesarRes()));
}

void Widget::addButton(QPushButton *btn, int row, int col, QString text, int w, int h)
{
    int x = 30 + (w + 15)*(row - 1);
    int y = 100 + (h + 15)*(col - 1);
    btn->setGeometry(x, y, w, h);
    btn->setText(text);
    connect(btn, SIGNAL(clicked()), this, SLOT(buttonPress()));
}
void Widget::buttonPress()
{
    QPushButton * btn = qobject_cast <QPushButton*> (sender());
    QString str = btn->text();
    if (str == "+")
    {
        edit->setText(" ");
        if (Z == "")
        {

        }
        else
        {

        }

    }
    else if (str == "-")
    {
        edit->setText(" ");
    }
    else if (str == "=")
    {
        edit->setText(" ");
    }
    else if (str == "/")
    {
        edit->setText(" ");
    }
    else if (str == "*")
    {
        edit->setText(" ");
    }
    else
    {
        buf += str;
    }
    //edit->setText(buf);
    //str = edit->text() + btn -> text();

    edit->setText(edit->text() + str);
}
//
