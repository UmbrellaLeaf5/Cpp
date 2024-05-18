#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);      // Отключаем оформление окна
                                                                                 // и делаем его всегда выше всех
    this->setAttribute(Qt::WA_TranslucentBackground);
    //this->setWindowOpacity( 0.8 );
    ui->widget->setStyleSheet("QWidget{background:#ff0000;}");
    ui->pushButton->setStyleSheet("QPushButton{"
                                  "background:#cccccc;"
                                  "color:#cc1111;"
                                  "border-radius:12px;"
                                  "border: 2px solid #ff0000;"
                                  "}");

    ui->graphicsView->setStyleSheet("QGraphicsView{background:rgba(0,0,0,0.8);}");
    scene = new paintScene();       // Инициализируем графическую сцену
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену
    ui->graphicsView->setRenderHint(QPainter::Antialiasing); //Сглаживаем линии

    timer = new QTimer();       // Инициализируем таймер
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimer()));
    timer->start(100);          // Запускаем таймер
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}

void MainWindow::slotTimer()
{
    /* Переопределяем размеры графической сцены в зависимости
     * от размеров окна
     * */
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
}
