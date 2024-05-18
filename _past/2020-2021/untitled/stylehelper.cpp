#include "stylehelper.h"

QString StyleHelper::getGameBtnStyle()
{
    return "QPushButton{"
            "color:red;"
            "font-size: 24px;"
            "}";
}

QString StyleHelper::getHelpBtnStyle()
{
    return "QPushButton{"
           "color:green;"
           "font-size: 14px;"
           "}";
}
