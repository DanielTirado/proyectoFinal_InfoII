#include "mono.h"
#include "mango.h"

mono::mono()
{

}

mono::mono(float _x, float _y, float _vx, float _vy, float width, float high)
{
    posx = _x;
    posy = _y;
    ancho = width;
    alto = high;
    vx = _vx;
    vy = _vy;
    setPos(posx, posy);
}

QRectF mono::boundingRect() const
{
    return QRect(-ancho, -alto, ancho*2, alto*2);
}

void mono::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkYellow);
    painter->drawRect(boundingRect());
}

void mono::saltar()
{
    //Calcular velocidades
    vy = vy + (G * DT);

    posx = posx + (-vx * DT);
    posy = posy + (-vy * DT) + (0.5 * G * pow(DT,2));

    setPos(posx, posy);
}
