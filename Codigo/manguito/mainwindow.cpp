#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mango.h"
#include "mono.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    easyMode = new QGraphicsScene(0,0,420,466);
    ui->graphicsView->setScene(easyMode);


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Animar()));

    timer->start(100);
    jugar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Animar()
{
    mangos[0]->pendulo();
}

void MainWindow::jugar()
{
    mangos.append(new mango(20,20,10,10,10));
    easyMode->addItem(mangos.last());
}

/*void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //QPoint po = event->pos();
    //mira->posx = po.x();
    //mira->posy = po.y();
}*/


