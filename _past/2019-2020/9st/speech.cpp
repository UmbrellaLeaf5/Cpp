#include "speech.h"
#include <time.h>
Speech::Speech()
{
    Init();
}

One_Speech Speech::getDialog()
{
    srand(time(NULL));
    int R = rand() % dialogs.length();
    return dialogs.at(R);
}
void Speech::Init()
{
    One_Speech d;
    d.fraction = "АРМИЯ";
    d.text = "Военные просят провести"
            "масштабные учения.";
    d.price = 50000;
    dialogs.append(d);
    d.fraction = "Т. ПОЛИЦИЯ";
    d.text = "Для улучшения качества работы "
            "необходимо 20000.";
    d.price = 20000;
    dialogs.append(d);
    d.fraction = "ФЕРМЕРЫ";
    d.text = "Запрпетить эмиграцию";
    d.price = 20000;
}
