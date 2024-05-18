#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFileDialog>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include "imageitem.h"
#include "math.h"
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageLabel = new QLabel(this);
    imageLabel->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
    ui->scrollArea->setWidget(imageLabel);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                       "Выбрать изображение", "",
                        "Изображения (*.bmp  *.jpg *.png)");
    QPixmap pix(fileName);
    imageLabel->setPixmap(pix);
    imageLabel->setFixedSize(pix.width(),pix.height());
    setImagesList(fileName);

}

void MainWindow::on_action_3_triggered()
{
    this->close();
}

void MainWindow::setImagesList(QString filename)
{
    ui->listWidget->clear();
    QFileInfo info(filename);
    QDir dir(info.absolutePath());
    QStringList filter;
    filter << "*.jpg" << "*.png" << "*.bmp";
    QFileInfoList list =  dir.entryInfoList(filter);
    for (int i=0;i<list.count();i++) {
         QFileInfo f = list.at(i);
         QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
         ImageItem *imgitem = new ImageItem;
         QPixmap pix(f.filePath());
         int w = pix.width();
         int h = pix.height();
         double filesize = f.size()/1024.0;
         QString resStr = QString::number(w) + "x" + QString::number(h) + " ";
         resStr += QString::number(round(filesize*10)/10) + "KB";
         imgitem->setData(pix.scaledToWidth(80,Qt::SmoothTransformation),
                          f.fileName(),resStr, f.filePath());
         item->setSizeHint(imgitem->sizeHint());
         ui->listWidget->setItemWidget(item,imgitem);
    }
}
void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ImageItem *imgitem = qobject_cast <ImageItem*>
            (ui->listWidget->itemWidget(item));
    QPixmap pix(imgitem->getPath());
    imageLabel->setPixmap(pix);
    imageLabel->setFixedSize(pix.width(),pix.height());

}
