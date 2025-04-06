#include "stylehelper.h"



QString StyleHelper::getGameBtnStyle()
{
    return "QPushButton{"
           "background-image: url(:/images/btn_2.png);"
           "border:none;"
           "background-color:none;"
           "font: 16pt \"Elephant\";"
            "color: rgb(226, 226, 226);"
           "}"
           "QPushButton:hover{"
           "background-image: url(:/images/btn_1.png);"
           "}";
}

QString StyleHelper::getHelpBtnStyle()
{
    return "QPushButton{"
           "color:green;"
           "font-size:10px;"
           "}";
}

QString StyleHelper::getTabStyle()
{
    return "QWidget#tab{"
           "background-image: url(:/images/bg_1.png);"
           "background-position: center center;"
           "background-repeat: no-repeat;"
           "}";
}

QString StyleHelper::getTabWidgetStyle()
{
    return "QTabWidget::pane { "
            "border:none;"
            "background:none;"
           "}";
}

QString StyleHelper::getSlotStyle()
{
    return "QLabel{"
           "background-image: url(:/images/slot1.png);"
           "background-position: center center;"
           "background-repeat: no-repeat;"
           "}";
}

QString StyleHelper::getSelectSlotStyle()
{
    return "QLabel{"
           "background-image: url(:/images/slot1.png);"
           "background-position: center center;"
           "background-repeat: no-repeat;"
           "border:2px solid #f00;"
           "}";
}
