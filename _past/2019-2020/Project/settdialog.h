#ifndef SETTDIALOG_H
#define SETTDIALOG_H

#include <QDialog>

namespace Ui {
class SettDialog;
}

class SettDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettDialog(QWidget *parent = nullptr);
    ~SettDialog();
    // int Qwe = 0;
    int somethigTest = 0;

private slots:
    void on_pushButton_2_clicked();

    void on_checkBox_clicked();

    void on_pushButton_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::SettDialog *ui;

};

#endif // SETTDIALOG_H
