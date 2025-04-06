#ifndef EDITOR_H
#define EDITOR_H

#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QPlainTextEdit>
#include <QVBoxLayout>

class editor : public QWidget
{
    Q_OBJECT

public:
    explicit editor(QWidget *parent = nullptr);
    void setList(QStringList *list);
    QPlainTextEdit *edit;
    bool save;

private:
    QComboBox *combo;
    QVBoxLayout *box;

signals:

 public slots:
};

#endif // EDITOR_H
