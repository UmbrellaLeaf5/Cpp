#include "widget.h"
#include "ui_widget.h"
#include <QSqlRecord>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->dbConnect();
    this->loadAutors();
    this->loadAutorsToList();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::dbConnect()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("ExampleDB");
    db.setDatabaseName("ExampleDB");
    if(db.open()){
        ui->label_4->setText("Всё ОК!");
    }else{
        ui->label_4->setText("Нет коннекта!");
    }
}

void Widget::loadAutors()
{
    QSqlQuery query;
    QString qStr = "SELECT name "
    "FROM autors ORDER BY name";
    if(query.exec(qStr)){
        while (query.next()) {
            ui->comboBox->addItem(
                 query.value(0).toString());
        }

    }else{
        qDebug() << "Ошибка: " +
                    query.lastError().text();
    }
}

void Widget::loadAutorsToList()
{
    QSqlQuery query;
    QString qStr = "SELECT name "
    "FROM autors ORDER BY name";
    if(query.exec(qStr)){
        while (query.next()) {
            ui->listWidget->addItem(
                 query.value(0).toString());
        }

    }else{
        qDebug() << "Ошибка: " +
                    query.lastError().text();
    }
}


void Widget::on_pushButton_2_clicked()
{
    QSqlQuery query;
    QString qStr = ui->plainTextEdit->toPlainText();
    if(query.exec(qStr)){
        ui->label_4->setText("Выполенно!");
    }else{
        ui->label_4->setText(
          "Ошибка: " + query.lastError().text()
                            );
    }
}

void Widget::on_tabWidget_currentChanged(int index)
{
    if(index == 2){
        ui->listWidget_3->clear();
        QSqlQuery query;
        QString qStr = "SELECT name FROM sqlite_master "
                       "WHERE type='table'";
        if(query.exec(qStr)){
            while (query.next()) {
                ui->listWidget_3->addItem(
                      query.value(0).toString()
                 );
            }
        }
    }
}

void Widget::on_listWidget_3_currentTextChanged(const QString &currentText)
{
    for (int i=ui->tableWidget_3->rowCount()-1;i>=0 ;i-- ) {
         ui->tableWidget_3->removeRow(i);
    }
    for (int i=ui->tableWidget_3->columnCount()-1;i>=0 ;i-- ) {
        ui->tableWidget_3->removeColumn(i);
    }

    QSqlQuery query;
    if(query.exec("SELECT * FROM "+currentText)){
       qDebug() << "Number of Rows: " << query.size();
       qDebug() << "Number of columns: " << query.record().count();
       QSqlRecord localRecord = query.record();
       for (int i = 0; i < localRecord.count(); i++) {
            QString fieldName = localRecord.fieldName(i);
            ui->tableWidget_3->setColumnCount(ui->tableWidget_3->columnCount()+1);
            QTableWidgetItem* qtwi = new QTableWidgetItem(QString(fieldName),
            QTableWidgetItem::Type);
            ui->tableWidget_3->setHorizontalHeaderItem(i,qtwi);

       }
       int y = 0;
       while( query.next() ) {
          ui->tableWidget_3->insertRow(ui->tableWidget_3->rowCount());
          for (int i=0;i<query.record().count() ;i++ ) {
              QTableWidgetItem *item = new QTableWidgetItem(query.value(i).toString());
              ui->tableWidget_3->setItem(y,i,item);
          }
          y++;
       }
   }
}

void Widget::on_pushButton_3_clicked()
{
    QSqlQuery query;
    QString qStr = "INSERT INTO autors "
        "(name) VALUES('" +
        ui->lineEdit_2->text() +"')";
    if(query.exec(qStr)){
        ui->comboBox->clear();
        this->loadAutors();
        ui->lineEdit_2->clear();

    }else{
        qDebug() << "Ошибка: " +
                    query.lastError().text();
    }
}

void Widget::on_pushButton_4_clicked()
{
    QSqlQuery query;
    QString qStr = "SELECT id "
        "FROM autors WHERE name='"+
        ui->comboBox->currentText()
        +"'";
    QString id;
    if(query.exec(qStr)){
        while (query.next()) {
            id = query.value(0).toString();
        }
        qStr = "INSERT INTO albums "
        "(a_autor,a_name)"
        "VALUES"
        "('"+id+"','"+
        ui->lineEdit_3->text()+"')";
         if(query.exec(qStr)){

         }else{
             qDebug() << "Ошибка: " +
             query.lastError().text();
         }
    }else{
        qDebug() << "Ошибка: " +
                    query.lastError().text();
    }
}

void Widget::on_listWidget_currentTextChanged(const QString &currentText)
{
    QSqlQuery query;
    QString qStr = "SELECT id "
        "FROM autors WHERE name='"+
        currentText
        +"'";
    QString id;
    if(query.exec(qStr)){
        while (query.next()) {
            id = query.value(0).toString();
        }
        qStr = "SELECT a_name FROM albums "
               "WHERE a_autor='"+id+"'";
         if(query.exec(qStr)){
             ui->listWidget_2->clear();
             while (query.next()) {
                 ui->listWidget_2->addItem(
                  query.value(0).toString());
             }
         }else{
             qDebug() << "Ошибка: " +
             query.lastError().text();
         }
    }else{
        qDebug() << "Ошибка: " +
                    query.lastError().text();
    }
}

void Widget::on_pushButton_5_clicked()
{
    QSqlQuery query;

    QString author = ui->listWidget->
            currentItem()->text();
    QString qStr = "SELECT id FROM autors"
                   " WHERE name ='"+author+"'";
    QString id;
    if(query.exec(qStr)){
        while(query.next())
        {
            id = query.value(0).toString();
        }
        qStr = "delete from albums "
                "where a_autor '"+id+"'";
        if(query.exec(qStr))
        {
            ui->listWidget->clear();
            ui->listWidget_2->clear();
            loadAutorsToList();
        }else{
            qDebug() << "Ошибка: " + query.lastError().text();
        }

    }
}

void Widget::on_pushButton_6_clicked()
{
    QSqlQuery query;
    QString author = ui->listWidget->
            currentItem()->text();
    QString album = ui->listWidget_2->
            currentItem()->text();
    QString qStr_aut = "SELECT id FROM autors"
                   " WHERE name ='"+author+"'";
    QString id_aut;
    if(query.exec(qStr_aut)){
        while(query.next())
        {
            id_aut = query.value(0).toString();
        }
    }
    QString qStr_alb = "SELECT a_id FROM albums"
                       " WHERE (a_name ='"+album+"'"
                       " and a_autor ='"+id_aut+"')";
    QString id_alb;
    if(query.exec(qStr_alb)){
        while(query.next())
        {
            id_alb = query.value(0).toString();

        }
        if(query.exec(qStr_alb))
        {
            qStr_alb = "delete from albums "
                    "where a_id = '"+id_alb+"'";
            query.exec(qStr_alb);
            ui->listWidget_2->clear();
            on_listWidget_currentTextChanged(author);
        }else{
            qDebug() << "Ошибка: " + query.lastError().text();
        }
    }else{
        qDebug() << "Ошибка: " + query.lastError().text();
    }

}

void Widget::on_listWidget_2_currentTextChanged(const QString &currentText)
{

}

void Widget::on_pushButton_clicked()
{
    QSqlQuery query;
    QString text = ui->lineEdit->text();
    QString str = "select * from autors "
            "where name like '%'"+text+"'%' "
            "order by name";
    if(query.exec(str)){
        ui->listWidget->clear();
        ui->listWidget_2->clear();
        while(query.next())
        {
            ui->listWidget->addItem(query.value(0).toString());
        }
    }else{
        qDebug() << "Ошибка: " + query.lastError().text();
    }
}
