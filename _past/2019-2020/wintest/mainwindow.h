#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

struct Question
{
    QString text;
    QString answer_1;
    QString answer_2;
    QString answer_3;
    int weight = 1;
    QString img;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Question QuestList[50];
    void setQuestions();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    int qIndex = 0;
    void showQuestion(int index);
    void nextQuestion();
};

#endif // MAINWINDOW_H
