#ifndef LABELITEM_H
#define LABELITEM_H

#include <QLabel>

class LabelItem : public QLabel
{
    Q_OBJECT

public:
    LabelItem();
    int getID();
    void setID(int id);

private:
    int id;
};

#endif // LABELITEM_H
