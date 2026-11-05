#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_toolButton_clicked();

    void on_tabWidget_tabCloseRequested(int index);

    void on_action_triggered();

    void on_action_2_triggered();
    void changeName();

    void on_action_4_triggered();

    void on_action_3_triggered();

    void on_action_5_triggered();

private:
    Ui::MainWindow *ui;
    QStringList * list;
};

#endif // MAINWINDOW_H
