#include "mono.h"
#include "mango.h"

mono::mono()
{

}

mono::mono(float _x, float _y, float width, float high)
{
    posx = _x;
    posy = _y;
    ancho = width;
    alto = high;
    v0 = 80.0;
    angulo = M_PI * 85.0 / 180.0;
    vx = v0 * cos(angulo)+10;
    flagSaltar = true;
    t = 0;
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
    if (flagSaltar){

        t += DT*3;

        vy = v0 * sin(angulo) - G * t;
        float X = posx + vx * t;
        float Y = posy - vy * t - (0.5 * G * t * t);

        setPos(X, Y);
    }
}
