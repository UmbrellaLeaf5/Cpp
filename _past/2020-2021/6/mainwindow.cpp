#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editor.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
    editor * editor1 = new editor(this);

    editor1->setList(list);
    QString str = "New " + QString::number(ui->tabWidget->currentIndex() +2);
    connect(editor1->edit, SIGNAL(textChanged()), this, SLOT(changeName()));
    ui->tabWidget->addTab(editor1, str);
    int index = ui->tabWidget->count() -1;
    ui->tabWidget->setCurrentIndex(index);
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if(ui->tabWidget->count()>1)
    {
        ui->tabWidget->removeTab(index);
    }
    else
    {
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
    for( int i = 0; i <ui->tabWidget->count(); i++)
    {
        editor *ed = qobject_cast<editor*>(ui->tabWidget->widget(i));
        if(ed->save == false)
        {
            flag = false;
        }
    }
    if (flag == false)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Warning!", "Unsaved tab(s) detected." " Do you want to exit?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
                this->close();
        }
    }
}

void MainWindow::changeName()
{

    editor *ed = qobject_cast<editor*>(ui->tabWidget->widget(ui->tabWidget->currentIndex()));
    if (ed->save == true)
    {
        QString str = ui->tabWidget->tabText(ui->tabWidget->currentIndex());
        str = "*" + str;
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), str);
        ed->save = false;
    }
    setWindowTitle("Text changed");
}
