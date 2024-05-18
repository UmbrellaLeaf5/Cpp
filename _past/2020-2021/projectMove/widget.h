#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void deleteCheese(QGraphicsItem *item);

private:
    Ui::Widget *ui;
    QTimer *timer;
    QGraphicsScene *scene;
    QList <QGraphicsItem *> cheese;
};
#endif // WIDGET_H
