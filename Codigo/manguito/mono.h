#ifndef MONO_H
#define MONO_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <cmath>

class mono : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

private:
    float pos0x, pos0y, vx, vy, ancho, alto, v0, angulo, t, dir, posx, posy;

public:
    mono();
    mono(float _x, float _y, float width, float high);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QTimer *timerMono;
    QPixmap *pixmap;

    bool flagSaltar;
    bool direccion;

    bool mover;

    float getX();
    float getY();

    void setX(float value);
    void setY(float value);

    void saltar();
    void cambio();
    void caidaLibre();
};

#endif // MONO_H
