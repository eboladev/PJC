#ifndef INTRUDER_H
#define INTRUDER_H

#include "mobileobject.h"
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QVector>

class Intruder : public MobileObject
{
public:
    Intruder();
    //void hide();
    int intruderDirection;

private:
    QPixmap intruderUp;
    QPixmap intruderDown;
    QPixmap intruderLeft;
    QPixmap intruderRight;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // INTRUDER_H
