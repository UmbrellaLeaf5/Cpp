#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QPushButton *button;
public slots:
    void hello();
};
#endif // WIDGET_H
