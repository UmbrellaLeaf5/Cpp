#include "widget.h"

#include <stdio.h>
#include <string.h>

#include <QDir>
#include <QFileInfo>

#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }

void Widget::on_pushButton_clicked() {
  QDir().mkdir("C:\\Junk");

  QString str = ui->lineEdit->text().trimmed();
  QString str2 = ui->lineEdit_1->text().trimmed();
  QString str3 = ui->lineEdit_1_1->text().trimmed();

  if (str == "") str = "193";
  if (str2 == "") str2 = "100";
  if (str3 == "") str3 = "39";

  QFile file("C:\\Junk\\C1R.txt");
  file.open(QIODevice::WriteOnly);
  file.write(qPrintable(str));
  file.close();

  QFile file2("C:\\Junk\\C1G.txt");
  file2.open(QIODevice::WriteOnly);
  file2.write(qPrintable(str2));
  file2.close();

  QFile file3("C:\\Junk\\C1B.txt");
  file3.open(QIODevice::WriteOnly);
  file3.write(qPrintable(str3));
  file3.close();
}

void Widget::on_pushButton_2_clicked() {
  QDir().mkdir("C:\\Junk");

  QString str = ui->lineEdit_2->text().trimmed();
  QString str2 = ui->lineEdit_2_2->text().trimmed();
  QString str3 = ui->lineEdit_2_2_2->text().trimmed();

  if (str == "") str = "122";
  if (str2 == "") str2 = "67";
  if (str3 == "") str3 = "30";

  QFile file("C:\\Junk\\C2R.txt");
  file.open(QIODevice::WriteOnly);
  file.write(qPrintable(str));
  file.close();

  QFile file2("C:\\Junk\\C2G.txt");
  file2.open(QIODevice::WriteOnly);
  file2.write(qPrintable(str2));
  file2.close();

  QFile file3("C:\\Junk\\C2B.txt");
  file3.open(QIODevice::WriteOnly);
  file3.write(qPrintable(str3));
  file3.close();
}

void Widget::on_pushButton_3_clicked() {
  QDir().mkdir("C:\\Junk");

  QString str = ui->lineEdit_3->text().trimmed();
  QString str2 = ui->lineEdit_3_3->text().trimmed();
  QString str3 = ui->lineEdit_3_3_3->text().trimmed();

  if (str == "") str = "90";
  if (str2 == "") str2 = "50";
  if (str3 == "") str3 = "23";

  QFile file("C:\\Junk\\C3R.txt");
  file.open(QIODevice::WriteOnly);
  file.write(qPrintable(str));
  file.close();

  QFile file2("C:\\Junk\\C3G.txt");
  file2.open(QIODevice::WriteOnly);
  file2.write(qPrintable(str2));
  file2.close();

  QFile file3("C:\\Junk\\C3B.txt");
  file3.open(QIODevice::WriteOnly);
  file3.write(qPrintable(str3));
  file3.close();
}

void Widget::on_pushButton_4_clicked() {
  QDir().mkdir("C:\\Junk");

  QString str = ui->lineEdit_4->text().trimmed();
  QString str2 = ui->lineEdit_4_4->text().trimmed();
  QString str3 = ui->lineEdit_4_4_4->text().trimmed();

  if (str == "") str = "78";
  if (str2 == "") str2 = "41";
  if (str3 == "") str3 = "15";

  QFile file("C:\\Junk\\C4R.txt");
  file.open(QIODevice::WriteOnly);
  file.write(qPrintable(str));
  file.close();

  QFile file2("C:\\Junk\\C4G.txt");
  file2.open(QIODevice::WriteOnly);
  file2.write(qPrintable(str2));
  file2.close();

  QFile file3("C:\\Junk\\C4B.txt");
  file3.open(QIODevice::WriteOnly);
  file3.write(qPrintable(str3));
  file3.close();
}

void Widget::on_pushButton_5_clicked() {
  QDir().mkdir("C:\\Junk");

  QString str = ui->lineEdit_5->text().trimmed();
  QString str2 = ui->lineEdit_5_5->text().trimmed();
  QString str3 = ui->lineEdit_5_5_5->text().trimmed();

  if (str == "") str = "47";
  if (str2 == "") str2 = "27";
  if (str3 == "") str3 = "14";

  QFile file("C:\\Junk\\C5R.txt");
  file.open(QIODevice::WriteOnly);
  file.write(qPrintable(str));
  file.close();

  QFile file2("C:\\Junk\\C5G.txt");
  file2.open(QIODevice::WriteOnly);
  file2.write(qPrintable(str2));
  file2.close();

  QFile file3("C:\\Junk\\C5B.txt");
  file3.open(QIODevice::WriteOnly);
  file3.write(qPrintable(str3));
  file3.close();
}

void Widget::on_pushButton_6_clicked() {
  QDir().mkdir("C:\\Junk");

  QString str = ui->lineEdit_6->text().trimmed();
  QString str2 = ui->lineEdit_6_6->text().trimmed();
  QString str3 = ui->lineEdit_6_6_6->text().trimmed();

  if (str == "") str = "24";
  if (str2 == "") str2 = "14";
  if (str3 == "") str3 = "8";

  QFile file("C:\\Junk\\C6R.txt");
  file.open(QIODevice::WriteOnly);
  file.write(qPrintable(str));
  file.close();

  QFile file2("C:\\Junk\\C6G.txt");
  file2.open(QIODevice::WriteOnly);
  file2.write(qPrintable(str2));
  file2.close();

  QFile file3("C:\\Junk\\C6B.txt");
  file3.open(QIODevice::WriteOnly);
  file3.write(qPrintable(str3));
  file3.close();
}

void Widget::on_pushButton_7_clicked() {
  on_pushButton_clicked();
  on_pushButton_2_clicked();
  on_pushButton_3_clicked();
  on_pushButton_4_clicked();
  on_pushButton_5_clicked();
  on_pushButton_6_clicked();
}
