#include "settdialog.h"
#include "ui_settdialog.h"

SettDialog::SettDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettDialog)
{
    ui->setupUi(this);
}

SettDialog::~SettDialog()
{
    delete ui;
}

void SettDialog::on_pushButton_2_clicked()
{
    close();
}

void SettDialog::on_checkBox_clicked()
{
   somethigTest = 1;
}



void SettDialog::on_pushButton_clicked()
{

    if (somethigTest == 1)
     {
         close();
         somethigTest = 0;
     }

}

void SettDialog::on_checkBox_stateChanged(int arg1)
{

}
