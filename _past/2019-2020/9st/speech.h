#ifndef SPEECH_H
#define SPEECH_H
#include <QString>
#include <QVector>
struct One_Speech
{
    QString fraction;
    QString text;
    int price = 0;
};

class Speech
{
public:
    Speech();
    QVector <One_Speech> dialogs;
    One_Speech getDialog();

private:
void Init();
};
#endif // SPEECH_H
