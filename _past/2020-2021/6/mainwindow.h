#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


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
    void on_toolButton_clicked();

    void on_tabWidget_tabCloseRequested(int index);

    void on_action_triggered();

    void on_action_2_triggered();

    void changeName();
    //QString str

private:
    Ui::MainWindow *ui;
    QStringList *list;
};
#endif // MAINWINDOW_H
