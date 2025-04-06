#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //Объявление кнопок
    QPushButton *b_0;
    QPushButton *b_1;
    QPushButton *b_2;
    QPushButton *b_3;
    QPushButton *b_4;
    QPushButton *b_5;
    QPushButton *b_6;
    QPushButton *b_7;
    QPushButton *b_8;
    QPushButton *b_9;
    QPushButton *b_plus;
    QPushButton *b_minus;
    QPushButton *b_res;
    QPushButton *b_clear;
    QLineEdit *edit;

public slots:
    void cesarRes();
    void pressKey();
};
#endif // WIDGET_H

