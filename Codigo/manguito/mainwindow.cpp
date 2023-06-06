#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mango.h"
#include "mono.h"
#include "mira.h"
#include "piedra.h"

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

    timer->start(20);
    drawNivel('1');
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
    QList<QGraphicsRectItem*>::Iterator it;
    for (it=ramas.begin(); it!=ramas.end(); it++){
        if(monos[0]->collidesWithItem(*it)){
            monos[0]->flagSaltar=false;
        }
    }

    /*for (int i=0; i<mangos.length(); i++){
        if (mangos[i]->tambalear) mangos[i]->pendulo();
        else mangos[i]->caidaLibre();
    }*/
    QList<mango*>::Iterator ite;
    for (ite=mangos.begin(); ite!=mangos.end(); ite++){
        if((*ite)->tambalear) (*ite)->pendulo();
        else{
            (*ite)->caidaLibre();
            //mangos.erase(ite);
        }
    }


    miraCursor->posicion();
}

void MainWindow::jugar()
{
    monos.append(new mono(400, 200, 10, 10));
    easyMode->addItem(monos.last());


    miraCursor = new mira(500, 500, 15);
    easyMode->addItem(miraCursor);
}

void MainWindow::drawNivel(char level)
{
    //Dibujar Ramas
    ifstream F_ramas;
    string linea;
    int _x, _y, _w, _h;

    F_ramas.open("posRamas.txt");

    while(F_ramas.good()){
        getline(F_ramas, linea);

        int pos = 0;

        string numero;

        pos = linea.find(":");
        numero = linea.substr(0, pos);
        _x = stoi(numero);
        linea.erase(0, pos + 1);

        pos = linea.find(":");
        numero = linea.substr(0, pos);
        _y = stoi(numero);
        linea.erase(0, pos + 1);

        pos = linea.find(":");
        numero = linea.substr(0, pos);
        _w = stoi(numero);
        linea.erase(0, pos + 1);

        _h = stoi(linea);

        ramas.append(new QGraphicsRectItem(_x,_y, _w, _h));
        easyMode->addItem(ramas.back());
        ramas.back()->hide();
    }
    F_ramas.close();


    /* Dibujar Mangos
    ifstream F_mangos;

    F_ramas.open(fileLevel);

    while(F_mangos.good()){
        getline(F_mangos, linea);

        int pos = 0;
        string numero;

        pos = linea.find(":");
        numero = linea.substr(0, pos);
        _x = stoi(numero);
        linea.erase(0, pos + 1);

        pos = linea.find(":");
        numero = linea.substr(0, pos);
        _y = stoi(numero);
        linea.erase(0, pos + 1);

        mangos.append(new mango(_x,_y,20,25,40));
        easyMode->addItem(mangos.last());
    }
    F_mangos.close();*/


    random_device rd;
    mt19937 rng(rd());
    int min_X = 20;
    int max_X = 1000;
    int min_Y = 20;
    int max_Y = 400;
    uniform_int_distribution<int> uni1(min_X, max_X);
    uniform_int_distribution<int> uni2(min_Y, max_Y);
    uniform_real_distribution<float> uni3(0.1, 0.5);

    int cantidad_mangos = 0;
    switch (level) {
    case '1':
        cantidad_mangos = 20;
        break;
    case '2':
        cantidad_mangos = 15;
        break;
    case '3':
        cantidad_mangos = 10;
        break;
    default:
        break;
    }

    for (int i=0; i<cantidad_mangos; i++){
        int posX = uni1(rng);
        int posY = uni2(rng);
        float dt = uni3(rng);

        mangos.append(new mango(posX,posY,20,25,40,dt));
        easyMode->addItem(mangos.last());
    }


}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint po = event->pos();
    miraCursor->setX(po.x()-13);
    miraCursor->setY(po.y()-13);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint po = event->pos();
    if(event->MouseButtonPress){

        /*roca = new piedra(po.x(), po.y(), 30.0);
        easyMode->addItem(roca);*/


        QList<mango*>::Iterator it;
        for (it=mangos.begin(); it!=mangos.end(); it++){
            if (miraCursor->collidesWithItem(*it)){
                (*it)->tambalear = false;
            }
        }
    }
}
