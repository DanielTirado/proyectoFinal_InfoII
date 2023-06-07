#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QTimer>
#include <QGraphicsView>
#include <QList>

#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <QMouseEvent>

//LLevar tiempo
#include <chrono>
#include <thread>
#include <ctime>
#include <cstdlib>

#include <mango.h>
#include <mono.h>
#include <mira.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void disparoMono(int);
    void disparoMango(int);

public slots:
    void Animar();
    void aumentarScore();
    void restarScore();
    void aumentarSeg();

private slots:
    void on_pushButton_facil_clicked();

    void on_pushButton_medio_clicked();

    void on_pushButton_dificil_clicked();

private:

    Ui::MainWindow *ui;

    QGraphicsScene *WindowGame;
    QGraphicsScene *InicioGame;

    QTimer *timer;
    QTimer *relojTimer;

    int score, tiempo;
    char nivel;

    mira* miraCursor;
    QGraphicsRectItem* centroMira;
    QList <mango*> mangos;
    QList <mono*> monos;
    QList <QGraphicsRectItem*> ramas;

    void jugar();
    void inicio();
    void drawNivel(char level);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
