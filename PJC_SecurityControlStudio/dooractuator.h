#ifndef DOORACTUATOR_H
#define DOORACTUATOR_H

#include "actuator.h"
#include <QDebug>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QVector>
#include <QPoint>

class DoorActuator : public Actuator, public QGraphicsItem
{
public:
    DoorActuator();
    DoorActuator(QPoint a, QPoint b, int id);
    int doorClose;
    int doorOpen;

private:
    QPixmap door;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPoint point1;
    QPoint point2;
};

#endif // DOORACTUATOR_H
