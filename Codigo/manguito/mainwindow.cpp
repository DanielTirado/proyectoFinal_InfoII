#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mango.h"
#include "mono.h"
#include "mira.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    easyMode = new QGraphicsScene(0,0,1080,608);
    easyMode->setBackgroundBrush(QBrush(QImage(":/images/fondo_arbol_redimension.png")));
    ui->graphicsView->setScene(easyMode);
    //easyMode->addRect(easyMode->sceneRect());

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Animar()));

    timer->start(30);
    jugar();

    setMouseTracking(true);
    ui->centralwidget->setAttribute(Qt::WA_TransparentForMouseEvents);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Animar()
{
    monos[0]->saltar();

    for (int i=0; i<mangos.length(); i++){
        if (mangos[i]->tambalear) mangos[i]->pendulo();
        else mangos[i]->caidaLibre();
    }

    miraCursor->posicion();
}

void MainWindow::jugar()
{
    mangos.append(new mango(300,150,20,25,40));
    easyMode->addItem(mangos.last());
    mangos.append(new mango(500,300,20,25,40));
    easyMode->addItem(mangos.last());
    mangos.append(new mango(800,300,20,25,40));
    easyMode->addItem(mangos.last());

    monos.append(new mono(200,200,1,1,10,10));
    easyMode->addItem(monos.last());

    ramas.append(new QGraphicsRectItem(400,400,100,30));
    easyMode->addItem(ramas.last());

    miraCursor = new mira(500, 500, 25);
    easyMode->addItem(miraCursor);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint po = event->pos();
    miraCursor->setX(po.x()-9);
    miraCursor->setY(po.y()-9);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->MouseButtonPress){
        QList<mango*>::Iterator it;
        for (it=mangos.begin(); it!=mangos.end(); it++){
            if (miraCursor->collidesWithItem(*it)){
                (*it)->tambalear = false;
            }
        }
    }
}


