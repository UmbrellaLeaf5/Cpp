#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editor.h"
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    list = new QStringList;
    list->append("Без категории");
    list->append("Категория 2");
    list->append("Категория 3");
    ui->tabWidget->clear();
    on_toolButton_clicked();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    Editor * editor = new Editor(this);
    editor->setList(list);
    QString str = "New ";
    str += QString::number(ui->tabWidget->count()+1);
    connect(editor->edit,
            SIGNAL(textChanged()),
            this,
            SLOT(changeName()));
    ui->tabWidget->addTab(editor,str);
    int index = ui->tabWidget->count()-1;
    ui->tabWidget->setCurrentIndex(index);

}
void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if(ui->tabWidget->count()>1){
        ui->tabWidget->removeTab(index);
    }else {
        this->close();
    }
}

void MainWindow::on_action_triggered()
{
    on_toolButton_clicked();
}

void MainWindow::on_action_2_triggered()
{
    bool flag = true;
    int count = ui->tabWidget->count();
    for (int i=0;i<count;i++) {
        Editor *ed =  qobject_cast<Editor*>
                (ui->tabWidget->widget(i));
        if(ed->save == false){
            flag = false;
        }
    }
    if(flag == false){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this,
                                      "Внимание",
                                      "Некоторые файлы не сохранены. "
                                      "Выйти?",
                                      QMessageBox::Yes |
                                      QMessageBox::No);
        if(reply == QMessageBox::Yes){
            this->close();
        }
    }

}

void MainWindow::changeName(){
    //float F = static_cast<float>(10);
    int index = ui->tabWidget->currentIndex();
    Editor *ed =  qobject_cast<Editor*>
            (ui->tabWidget->widget(index));
    if(ed->save == true){
        QString str = ui->tabWidget->tabText(index);
        str = "*"+str;
        ui->tabWidget->setTabText(index, str);
        ed->save = false;
    }
}

void MainWindow::on_action_4_triggered()
{

    int index = ui->tabWidget->currentIndex();
    Editor *ed =  qobject_cast<Editor*>
            (ui->tabWidget->widget(index));
    if(ed->filename.length()==0){
        on_action_5_triggered();
    }else{
        QFile file(ed->filename);
        file.open(QIODevice::WriteOnly);
        file.write(ed->edit->toPlainText().toUtf8());
        file.close();
        ed->save = true;
        QFileInfo finfo(file);
        ui->tabWidget->setTabText(index,
                                  finfo.fileName());
    }

}

void MainWindow::on_action_3_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
                this,"Открыть");
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    on_toolButton_clicked();
    int index = ui->tabWidget->currentIndex();
    Editor *ed =  qobject_cast<Editor*>
            (ui->tabWidget->widget(index));

    ed->edit->setPlainText(file.readAll());
    QFileInfo finfo(file);
    ui->tabWidget->setTabText(index,
                              finfo.fileName());
    ed->save = true;
    ed->filename = filename;
    file.close();

}

void MainWindow::on_action_5_triggered()
{
    QString filename = QFileDialog::getSaveFileName(
                this,
                "Сохранить как");
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    int index = ui->tabWidget->currentIndex();
    Editor *ed =  qobject_cast<Editor*>
            (ui->tabWidget->widget(index));
    file.write(ed->edit->toPlainText().toUtf8());
    ed->filename = filename;
    file.close();
}
