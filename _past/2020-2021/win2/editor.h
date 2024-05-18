#ifndef EDITOR_H
#define EDITOR_H

#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QPlainTextEdit>
#include <QVBoxLayout>

class Editor : public QWidget
{
    Q_OBJECT
public:
    explicit Editor(QWidget *parent = nullptr);
    void setList(QStringList *list);
    QPlainTextEdit *edit;
    bool save;
    QString filename;
    QComboBox *combo;

private:
    QVBoxLayout *box;

signals:

public slots:
};

#endif // EDITOR_H
