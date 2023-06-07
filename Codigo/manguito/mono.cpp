#include "mono.h"
#include "mango.h"

mono::mono()
{

}

mono::mono(float _x, float _y, float width, float high)
{
    pos0x = _x;
    pos0y = _y;
    ancho = width;
    alto = high;
    v0 = 60.0;
    angulo = M_PI * 85.0 / 180.0;
    vx = v0 * cos(angulo)+10;
    flagSaltar = true;
    t = 0;
    dir = 1;

    mover=true;
    setPos(pos0x, pos0y);
}

QRectF mono::boundingRect() const
{
    return QRect(-ancho, -alto, ancho, alto);
}

void mono::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/images/mono.png");
    painter->drawPixmap(boundingRect(), pixmap, pixmap.rect());
}

float mono::getX()
{
    return posx;
}

float mono::getY()
{
    return posy;
}

void mono::saltar()
{
    if (mover){
        float X=0;
        float Y=0;
        if (!flagSaltar){
            dir *= (-1);
            pos0y = posy;
            pos0x = posx;
            t=0;
            v0 = 25.0;
            flagSaltar = true;
        }
        else v0 = 60.0;


        t += DT*3;

        vy = v0 * sin(angulo) - G * t;
        X = pos0x + dir*vx * t;
        Y = pos0y - vy * t - (0.5 * G * t * t);

        posx = X;
        posy = Y;
        setPos(X, Y);
    }
}

void mono::cambio()
{
    flagSaltar = false;
}

void mono::caidaLibre()
{
    static float Y=0, V=0;
    V = abs(vy) + G*8;
    Y = posy + V*0.15 + (0.5*G*pow(DT,2));
    posy = Y;

    setPos(posx, Y);
}
