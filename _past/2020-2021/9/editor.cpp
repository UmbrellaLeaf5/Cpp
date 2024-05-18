#include "editor.h"

Editor::Editor(QWidget *parent) : QWidget(parent)
{
    box = new QVBoxLayout(this);
    edit = new QPlainTextEdit(this);
    combo = new QComboBox(this);
    box->addWidget(combo);
    box->addWidget(edit);
    save = true;
}

void Editor::setList(QStringList* list)
{
    combo->addItems(*list);

}
