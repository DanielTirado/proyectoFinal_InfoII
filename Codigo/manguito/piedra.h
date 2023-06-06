#ifndef PIEDRA_H
#define PIEDRA_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class piedra : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
private:
    float posx, posy, radio, velocidad, fila, columnas;
public:
    piedra();
    piedra(int x, int y, int r);
    QRectF boundingRect() const;

    QTimer *timer;
    QPixmap *pixmap;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void Actualizacion();
};

#endif // PIEDRA_H
