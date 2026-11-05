#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
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

private:
    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    QGraphicsRectItem * rect;
    QTimer *timer;
    QTimer *sc_timer;
    int alarm_count = 0;
};
#endif // MAINWINDOW_H
