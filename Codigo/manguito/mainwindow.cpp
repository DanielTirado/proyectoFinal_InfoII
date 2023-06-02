#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mango.h"
#include "mono.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    easyMode = new QGraphicsScene(550,170,420,466);
    easyMode->setBackgroundBrush(QBrush(QImage(":/images/fondo_arbol_redimension.png")));
    ui->graphicsView->setScene(easyMode);
    //easyMode->addRect(easyMode->sceneRect());



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
    //monos[0]->saltar();
    mangos[0]->pendulo();
}

void MainWindow::jugar()
{
    mangos.append(new mango(300,150,20,25,40));
    easyMode->addItem(mangos.last());

    monos.append(new mono(200,200,40,20,10,10));
    easyMode->addItem(monos.last());
}

/*void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //QPoint po = event->pos();
    //mira->posx = po.x();
    //mira->posy = po.y();
}*/


