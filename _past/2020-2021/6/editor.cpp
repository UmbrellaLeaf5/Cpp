#include "editor.h"

editor::editor(QWidget *parent) : QWidget(parent)
{
    box = new QVBoxLayout(this);
    combo = new QComboBox(this);
    edit = new QPlainTextEdit(this);
    box->addWidget(combo);
    box->addWidget(edit);
    save = true;
}

void editor::setList(QStringList *list)
{
    combo->addItems(*list);
}
