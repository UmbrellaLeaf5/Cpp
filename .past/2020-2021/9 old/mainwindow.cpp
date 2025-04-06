#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setVisible(false);
    ui->pushButton_3->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QFile f("file.txt");
    f.open(QIODevice::WriteOnly|QIODevice::Text);
    f.write(ui->plainTextEdit->toPlainText().toUtf8());
    f.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QFile f("file.txt");
    f.open(QIODevice::ReadOnly|QIODevice::Text);
    QString content = f.readAll();
    QStringList list;
    list = content.split("\n");
    for(int i = 0; i < list.count(); i++)
    {
        list[i] = list[i].trimmed();
        if(list[i].trimmed().length() > 0)
        {
            ui->comboBox->addItem(list[i]);
        }
    }
    ui->comboBox->addItem("Create");
    f.close();

}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if( arg1 == "Create")
    {
        ui->lineEdit->setVisible(true);
        ui->pushButton_3->setVisible(true);
    }
    else
    {
        ui->lineEdit->setVisible(false);
        ui->pushButton_3->setVisible(false);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString str = ui->lineEdit->text();
    ui->comboBox->insertItem(ui->comboBox->currentIndex(), str);
    for (int i = 0; i < ui->comboBox->count()-1; i++)
    {
        QString str = ui->comboBox->itemText(i);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QFile f("file.txt");
    QString str;
    f.open(QIODevice::WriteOnly|QIODevice::Text);
    for(int i = 0; i < ui->comboBox->count() - 1; i++)
    {
        ui->comboBox->setCurrentIndex(i);
        str = ui->comboBox->currentText() + "\n";
        f.write(str.toUtf8());
    }
}
