#ifndef MANGO_H
#define MANGO_H

#define G 9.8
#define DT 0.1
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
    float posx, posy, ancho, alto, L, vy, dt, t_total;

public:
    mango();
    mango(float _x, float _y, float _ancho,
          float _alto, float _l, float _dt);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QTimer *timerMango;

    bool tambalear;

    void setX(float value);
    void setY(float value);

    float getX();
    float getY();

    void caidaLibre();
    void pendulo();
};
#endif // MANGO_H
