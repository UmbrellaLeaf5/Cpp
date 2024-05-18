#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>
#include "paintscene.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();
    void slotTimer();

private:
    Ui::MainWindow *ui;
    QTimer *timer;      /* Определяем таймер для подготовки актуальных размеров
                            * графической сцены
                            * */
    paintScene *scene;  // Объявляем кастомную графическую сцену
    /* Переопределяем событие изменения размера окна
         * для пересчёта размеров графической сцены
         * */
    void resizeEvent(QResizeEvent * event);
};

#endif // MAINWINDOW_H
