#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void updatePosition();
    void alarm();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    QGraphicsRectItem * rect;
    QTimer *timer;
    QTimer *sc_timer;
    int alarm_count = 0;
    QGraphicsPixmapItem *pix;
    void updateTexPos();
    int speedX = 1;
    int speedY = 0;
    int H = 1;
    int R = 1;
};
#endif // MAINWINDOW_H
