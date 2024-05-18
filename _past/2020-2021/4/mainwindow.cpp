#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTabWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("А ты догадливый)");
}
void MainWindow::on_pushButton_2_clicked()
{
    QString str = ui->label->text();
    ui->pushButton_2->setText(str);
}
void MainWindow::on_pushButton_3_clicked()
{
    ui->label->setText(ui->lineEdit->text());
}
void MainWindow::on_pushButton_4_clicked()
{
    ui->plainTextEdit->appendPlainText("Umbrella Leaf ");
}
void MainWindow::on_pushButton_5_clicked()
{
    ui->plainTextEdit->insertPlainText("and more Umbrella Leaves ");
}
void MainWindow::on_pushButton_6_clicked()
{
    QString str = ui->plainTextEdit->toPlainText();
    //setGeometry(100, 100, 100, 100);
    QMessageBox::warning(this, "UMBRELLA LEAF!!!", str);
}
void MainWindow::on_pushButton_7_clicked()
{
    QString str = QString::number(ui->spinBox->value());
    if (str == "0")
    {
        ui->lineEdit->setText("Spinbox is UMBRELLA LEAF!!!");
    }
    else
    {
        ui->lineEdit->setText("Spinbox is " + str);
    }
}
void MainWindow::hideButtons()
{
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
}
void MainWindow::showButtons()
{
    ui->pushButton_2->setVisible(true);
    //ui->pushButton->setVisible(true);
    ui->pushButton_3->setVisible(true);
}
void MainWindow::showAllButtons()
{
    ui->pushButton_2->setVisible(true);
    ui->pushButton->setVisible(true);
    ui->pushButton_3->setVisible(true);
}
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 1)
    {
        hideButtons();
    }
    else if (index == 2)
    {
        showButtons();
    }
    else if (index == 3)
    {
       showAllButtons();
    }
    else if (index == 4)
    {
        QWidget * tab_3 = new QWidget(this);
        ui->tabWidget->insertTab(0, tab_3, "Новая вкладка");
        ui->tabWidget->setCurrentIndex(0);
    }
}
