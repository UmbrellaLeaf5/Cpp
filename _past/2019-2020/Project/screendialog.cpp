#include "screendialog.h"
#include "ui_screendialog.h"

ScreenDialog::ScreenDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScreenDialog)
{
    ui->setupUi(this);
}

ScreenDialog::~ScreenDialog()
{
    delete ui;
}
