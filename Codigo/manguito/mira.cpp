#include "mira.h"

mira::mira(float _x, float _y, float r)
{
    posx = _x;
    posy = _y;
    radio = r;

}

QRectF mira::boundingRect() const
{
    return QRect(-radio, -radio, radio*2, radio*2);
}

void mira::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::darkRed);
    //painter->drawRect(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/images/mira.png");
    painter->drawPixmap(boundingRect(), pixmap, pixmap.rect());
}

void mira::posicion()
{
    setPos(posx, posy);
}

void mira::setX(float value)
{
    posx = value;
}

void mira::setY(float value)
{
    posy = value;
}
