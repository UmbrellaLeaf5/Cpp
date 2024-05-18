#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_2_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_listWidget_3_currentTextChanged(const QString &currentText);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_listWidget_currentTextChanged(const QString &currentText);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_listWidget_2_currentTextChanged(const QString &currentText);

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QSqlDatabase db;
    void dbConnect();
    void loadAutors();
    void loadAutorsToList();
};
#endif // WIDGET_H
