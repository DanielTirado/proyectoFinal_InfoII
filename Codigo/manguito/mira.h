#ifndef MIRA_H
#define MIRA_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QWidget>

class mira : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
private:
    float posx, posy, radio;
public:
    mira(float _x, float _y, float r);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void posicion();

    void setX(float value);
    void setY(float value);
};

#endif // MIRA_H
