#include "mango.h"

mango::mango()
{

}

mango::mango(float _x, float _y, float _ancho, float _alto, float _l)
{
    posx = _x;
    posy = _y;
    ancho = _ancho;
    alto = _alto;
    L = _l;
    setPos(posx, posy);
}

QRectF mango::boundingRect() const
{
    return QRect(-ancho, -alto, ancho*2, alto*2);
}

void mango::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkBlue);
    painter->drawEllipse(boundingRect());
}

void mango::pendulo()
{
    static float t = 0;
    t += DT;
    float w = sqrt(G/L);    //Frecuencia angular
    float angulo = THETA0 * cos(w*t); //Angulo en funcion del tiempo

    float X = posx + L * sin(angulo);
    float Y = posy + L * cos(angulo);

    setPos(X, Y);
}

void mango::seguirMono(float xMono, float yMono)
{
    setPos(xMono, yMono+10);
}

