#include "piedra.h"

piedra::piedra()
{

}

piedra::piedra(int x, int y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    velocidad=1;

    timer = new QTimer();

    fila = 0;
    columnas = 0;

    // pixmap = new QPixmap(":/Imagenes/sprites_pacman.png");

    timer->start(100);

    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizacion()));
}

QRectF piedra::boundingRect() const
{
    return QRectF(posx,posy,2*radio,2*radio);
}

void piedra::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(posx,posy,*pixmap,columnas,fila,2*radio,2*radio);
}

void piedra::Actualizacion()
{
    // tamaño de sprites
}
