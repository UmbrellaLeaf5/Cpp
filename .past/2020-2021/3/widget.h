#ifndef WIDGET_H
#define WIDGET_H
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    int N1, N2;
    QString buf;
    QString Z;

    QLineEdit *edit;
    QPushButton *b_1;
    QPushButton *b_2;
    QPushButton *b_3;
    QPushButton *b_plus;

    QPushButton *b_4;
    QPushButton *b_5;
    QPushButton *b_6;
    QPushButton *b_minus;

    QPushButton *b_7;
    QPushButton *b_8;
    QPushButton *b_9;
    QPushButton *b_div;

    QPushButton *b_0;
    QPushButton *b_mult;
    QPushButton *b_clear;
    QPushButton *b_eq;


    void setWinStyle();
    void setButton();
    void addButton( QPushButton * btn, int row, int col, QString text, int w =100, int h=75);

private slots:
    void buttonPress();
};
#endif // WIDGET_H
