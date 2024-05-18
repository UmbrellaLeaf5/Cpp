#include "widget.h"
#include "ui_widget.h"
#include <QSpacerItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QSpacerItem *spacer;
    spacer = new QSpacerItem(1,1, QSizePolicy::Fixed, QSizePolicy::Expanding);
    box = new QVBoxLayout;
    ui->scrollAreaWidgetContents->setLayout(box);
    box->addItem(spacer);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    count ++;
    LabelItem *lit = new LabelItem;
    lit->setID(count);
    lit->setText(QString::number(count) + ") Hi!");
    box->insertWidget(box->count()-1, lit);
}

void Widget::on_pushButton_2_clicked()
{
    int num = ui->lineEdit->text().toInt();
    for(int i = 0; i < box->count()-1; i++)
    {
        LabelItem * item = qobject_cast <LabelItem*>(box->itemAt(i)->widget());
        if(item -> getID() == num)
        {
            box->removeWidget(item);
            delete item;
            //box->removeItem(num);
        }
    }
}
