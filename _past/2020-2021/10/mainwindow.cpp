#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
    f.open(QIODevice::WriteOnly |
           QIODevice::Text);
    f.write(ui->plainTextEdit->
            toPlainText().toUtf8());
    f.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QFile f("file.txt");
    f.open(QIODevice::ReadOnly |
           QIODevice::Text);
    QString content;
    content = f.readAll();
    QStringList list;
    list = content.split("\n");
    ui->comboBox->clear();
    for (int i=0;i<list.count();i++) {
        list[i] = list[i].trimmed();
        if(list[i].length() >0){
            ui->comboBox->addItem(list[i]);
        }
    }
    ui->comboBox->addItem("Создать");
    f.close();

}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1=="Создать"){
        ui->lineEdit->setVisible(true);
        ui->pushButton_3->setVisible(true);

    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString str = ui->lineEdit->text().trimmed();
    if(str.length()>0){
        bool add = true;
        for (int i=0;i<ui->comboBox->count();i++){
            if(str.toLower() == ui->comboBox->
                           itemText(i).toLower()){
                add = false;
                break;
            }
        }
        if(add==true){
            int index = ui->comboBox->currentIndex();
            ui->comboBox->insertItem(index, str);
            int stop = ui->comboBox->count()-1;
            QFile f("file.txt");
            f.open(QIODevice::WriteOnly |
                   QIODevice::Text);
            for (int i=0;i<stop;i++){
                QString str = ui->comboBox->itemText(i);
                str += "\n";
            }
            f.close();
        }
    }
}
