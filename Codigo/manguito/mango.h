#ifndef MANGO_H
#define MANGO_H

#define G 9.8
#define DT 0.7
#define THETA0 3.1416/2

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <cmath>

class mango : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

private:
    float posx, posy, ancho, alto, L;

public:
    mango();
    mango(float _x, float _y, float _ancho, float _alto, float _l);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QTimer *timerMango;
    QPixmap *pixmap;


    void pendulo();
    void seguirMono(float xMono, float yMono);
    //void posiciones();

};
#endif // MANGO_H
