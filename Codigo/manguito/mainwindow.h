#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QTimer>
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

#include <mango.h>
#include <mono.h>
#include <mira.h>
#include <piedra.h>

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

public slots:
    void Animar();

private:

    Ui::MainWindow *ui;

    QGraphicsScene *easyMode;

    QTimer *timer;


    mira* miraCursor;
    piedra* roca;
    QGraphicsRectItem* centroMira;
    QList <mango*> mangos;
    QList <mono*> monos;
    QList <QGraphicsRectItem*> ramas;

    void jugar();
    void drawNivel(char level);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
