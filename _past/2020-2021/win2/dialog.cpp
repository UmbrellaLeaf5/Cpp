#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();
    str = str.trimmed();
    if(str.length() > 0)
    {
        this->accept();
    }
    else
    {
        QMessageBox::warning(this, "Ошибка!", "Имя категории должно быть заполнено.");
        ui->lineEdit->clear();
    }
}

QString Dialog::getName()
{
    return ui->lineEdit->text();
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
}


