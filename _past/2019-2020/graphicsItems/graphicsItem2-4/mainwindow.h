#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
 protected:
    bool eventFilter(QObject* obj, QEvent* event);

private:
    Ui::MainWindow *ui;


    QGraphicsScene * scene;
    QGraphicsRectItem * obj;
    QGraphicsPixmapItem * pix;
    QGraphicsRectItem * pointsArr[7][7];

    QTimer *timer;
    QString status;
    QString new_status;
    int repeat;
    int matrix[7][7] = { {-1, -1, -1, -1,  0, -1, -1},
                         {-1,  0,  0,  0,  0,  0, -1},
                         {-1,  0, -1, -1, -1,  0, -1},
                         { 0,  0,  0,  0,  0,  0, -1},
                         {-1,  0,  0,  0, -1, -1, -1},
                         {-1,  0,  0,  0,  0,  0, -1},
                         {-1, -1, -1, -1, -1, -1, -1}};

private slots:
    void updateObj();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
