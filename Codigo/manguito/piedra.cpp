#include "piedra.h"

piedra::piedra()
{

}

piedra::piedra(float x, float y, float r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    velocidad=1;

    timer = new QTimer();

    fila = 0;
    columnas = 0;

    pixmap = new QPixmap(":/images/roca_sprites_redimension.png");

    timer->start(100);

    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizacion()));
}

QRectF piedra::boundingRect() const
{
    return QRectF(posx,posy,2*radio,2*radio);
}

void piedra::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(posx+30,posy+30,*pixmap,0,fila,2*radio,2*radio);
}

void piedra::Actualizacion()
{
    fila += 60;
    if (fila >= 180) fila = 0;
    //this->hide();
}
