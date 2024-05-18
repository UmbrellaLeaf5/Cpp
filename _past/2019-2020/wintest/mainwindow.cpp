#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    setQuestions();
    showQuestion(0);
    ui->tabWidget->setCurrentIndex(1);
}
void MainWindow::setQuestions()
{
    QuestList[0].text = "Пример вопроса";
    QuestList[0].answer_1 = "Первый вариант";
    QuestList[0].answer_2 = "вар. 2";
    QuestList[0].answer_3 = "вар. 3";
    QuestList[0].weight = 2;
    QuestList[0].img = "image1.jpg";

    QuestList[1].text = "Пример вопроса 2";
    QuestList[1].answer_1 = "Первый вариант 1";
    QuestList[1].answer_2 = "вар. 21";
    QuestList[1].answer_3 = "вар. 31";
    QuestList[1].weight = 2;
    QuestList[1].img = "image2.jpg";
}

void MainWindow::showQuestion(int index)
{
    ui ->label_4 ->setText(QuestList[index].text);
    ui ->pushButton_2 ->setText(QuestList[index].answer_1);
    QPixmap pix;
    pix.load(QuestList[index].img);
    ui ->label_5 -> setPixmap(pix);
}

void MainWindow::on_pushButton_2_clicked()
{
    nextQuestion();
}

void MainWindow::on_pushButton_3_clicked()
{
    nextQuestion();
}

void MainWindow::on_pushButton_4_clicked()
{
    nextQuestion();
}
void MainWindow::nextQuestion()
{
    qIndex = qIndex + 1;
    showQuestion(qIndex);
    //qIndex += 1;
    //qIndex ++;
}
