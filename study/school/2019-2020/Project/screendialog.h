#ifndef SCREENDIALOG_H
#define SCREENDIALOG_H

#include <QDialog>

namespace Ui {
class ScreenDialog;
}

class ScreenDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScreenDialog(QWidget *parent = nullptr);
    ~ScreenDialog();

private:
    Ui::ScreenDialog *ui;
};

#endif // SCREENDIALOG_H
