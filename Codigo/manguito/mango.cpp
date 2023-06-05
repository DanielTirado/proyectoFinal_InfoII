#include "mango.h"
#include <QDebug>

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
    tambalear = true;
    vy = 120;

}

QRectF mango::boundingRect() const
{
    return QRect(-ancho, -alto, ancho*2, alto*2);
}

void mango::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/images/mango.png");
    painter->drawPixmap(boundingRect(), pixmap, pixmap.rect());
}

void mango::setX(float value)
{
    posx = value;
}

void mango::setY(float value)
{
    posy = value;
}

void mango::caidaLibre()
{
    static float Y=0, V=0;
    V = vy + G*DT;
    Y = posy + V*DT + (0.5*G*pow(DT,2));
    posy = Y;

    setPos(posx, Y);


}

void mango::pendulo()
{
    if (tambalear){
    static float t = 0;
    t += DT;
    float w = sqrt(G/L);    //Frecuencia angular
    float angulo = THETA0 * cos(w*t); //Angulo en funcion del tiempo

    float X = posx + L * sin(angulo);
    float Y = posy + L * cos(angulo);
    setPos(X, Y);
    }
}

void mango::seguirMono(float xMono, float yMono)
{
    setPos(xMono, yMono+10);
}

