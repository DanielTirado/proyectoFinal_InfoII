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

    WindowGame = new QGraphicsScene(0,0,1080,608);

    InicioGame = new QGraphicsScene(0,0,1080,608);

    WindowGame->setBackgroundBrush(QBrush(QImage(":/images/fondo_arbol_redimension.png")));

    InicioGame->setBackgroundBrush(QBrush(QImage(":/images/inicio.png")));
    ui->dificil->hide();
    ui->medio->hide();
    ui->facil->hide();
    ui->graphicsView->setScene(InicioGame);

    timer = new QTimer(this);
    relojTimer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(Animar()));
    connect(this,SIGNAL(disparoMango(int)),this,SLOT(aumentarScore()));
    connect(this,SIGNAL(disparoMono(int)),this,SLOT(restarScore()));
    connect(relojTimer, SIGNAL(timeout()), this, SLOT(aumentarSeg()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Animar()
{

    if (tiempo==31){
        chrono::seconds tiempoEspera(2);
        this_thread::sleep_for(tiempoEspera);
        ui->graphicsView->setScene(InicioGame);
        ui->dificil->hide();
        ui->medio->hide();
        ui->facil->hide();

        ui->pushButton_dificil->show();
        ui->pushButton_medio->show();
        ui->pushButton_facil->show();

        relojTimer->stop();
        timer->stop();
        setMouseTracking(false);
        ui->centralwidget->setAttribute(Qt::WA_TransparentForMouseEvents, false);



        QList<mango*>::Iterator ite;
        for (ite=mangos.begin(); ite!=mangos.end(); ite++){
            WindowGame->removeItem(*ite);
        }
        QList<QGraphicsRectItem*>::Iterator it;
        for (it=ramas.begin(); it!=ramas.end(); it++){
            WindowGame->removeItem(*it);
        }
        QList<mono*>::Iterator itMono;
        for (itMono=monos.begin(); itMono!=monos.end(); itMono++){
            WindowGame->removeItem(*itMono);
        }

        WindowGame->removeItem(miraCursor);
        delete miraCursor;

        monos.clear();
        mangos.clear();
        ramas.clear();
    }

    QList<mono*>::Iterator itMono;
    for (itMono=monos.begin(); itMono!=monos.end(); itMono++){
        if ((*itMono)->mover) (*itMono)->saltar();
        else (*itMono)->caidaLibre();

        QList<QGraphicsRectItem*>::Iterator it;
        for (it=ramas.begin(); it!=ramas.end(); it++){
            if((*itMono)->collidesWithItem(*it)) (*itMono)->cambio();
        }
    }

    QList<mango*>::Iterator ite;
    for (ite=mangos.begin(); ite!=mangos.end(); ite++){
        if((*ite)->tambalear) (*ite)->pendulo();
        else (*ite)->caidaLibre();
    }

    miraCursor->posicion();
}

void MainWindow::aumentarScore()
{
    score += 3;
    ui->lcdScore->display(score);
}

void MainWindow::restarScore()
{
    if (score>3) score -= 3;
    else score = 0;
    ui->lcdScore->display(score);
}

void MainWindow::aumentarSeg()
{
    tiempo += 1;
    ui->lcdTime->display(tiempo);
}

void MainWindow::jugar()
{
    score = 0;
    tiempo = 0;

    ui->lcdScore->display(score);
    ui->lcdTime->display(tiempo);

    ui->pushButton_dificil->hide();
    ui->pushButton_medio->hide();
    ui->pushButton_facil->hide();

    setMouseTracking(true);
    ui->centralwidget->setAttribute(Qt::WA_TransparentForMouseEvents);

    ui->graphicsView->setScene(WindowGame);
    timer->start(20);
    relojTimer->start(1000);
    drawNivel(nivel);
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
        WindowGame->addItem(ramas.back());
        ramas.back()->hide();
    }
    F_ramas.close();


    //Dibujar Mangos
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
    int cantidad_monos = 0;
    switch (level) {
    case '1':
        cantidad_mangos = 25;
        cantidad_monos = 3;

        ui->dificil->hide();
        ui->medio->hide();
        ui->facil->show();

        break;
    case '2':
        cantidad_mangos = 25;
        cantidad_monos = 10;

        ui->dificil->hide();
        ui->facil->hide();
        ui->medio->show();

        break;
    case '3':
        cantidad_mangos = 18;
        cantidad_monos = 10;

        ui->medio->hide();
        ui->facil->hide();
        ui->dificil->show();

        break;
    default:
        break;
    }

    int posX=0;
    int posY=0;
    for (int i=0; i<cantidad_mangos; i++){
        posX = uni1(rng);
        posY = uni2(rng);
        float dt = uni3(rng);

        mangos.append(new mango(posX,posY,20,25,40,dt));
        WindowGame->addItem(mangos.last());
    }

    //Dibujar monos
    for (int i=0; i<cantidad_monos; i++){
        posX = uni1(rng);
        posY = uni2(rng);
        monos.append(new mono(posX, posY, 80, 102));
        WindowGame->addItem(monos.last());
    }

    //Dibujar Mira
    miraCursor = new mira(500, 500, 15);
    WindowGame->addItem(miraCursor);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint po = event->pos();
    miraCursor->setX(po.x()-13);
    miraCursor->setY(po.y()-13);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    if(event->MouseButtonPress){
        QList<mango*>::Iterator it;
        for (it=mangos.begin(); it!=mangos.end(); it++){
            if (miraCursor->collidesWithItem(*it)){
                (*it)->tambalear = false;
                emit disparoMango(9);
            }
        }

        QList<mono*>::Iterator itMono;
        for (itMono=monos.begin(); itMono!=monos.end(); itMono++){
            if (miraCursor->collidesWithItem(*itMono)){
                (*itMono)->mover = false;
                emit disparoMono(9);
            }
        }
    }
}

void MainWindow::on_pushButton_facil_clicked()
{
    nivel='1';
    jugar();
}

void MainWindow::on_pushButton_medio_clicked()
{
    nivel='2';
    jugar();
}


void MainWindow::on_pushButton_dificil_clicked()
{
    nivel='3';
    jugar();
}

