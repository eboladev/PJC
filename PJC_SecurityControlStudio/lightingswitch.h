#ifndef LIGHTINGSWITCH_H
#define LIGHTINGSWITCH_H

#include "actuator.h"
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QVector>
#include <QPoint>


class LightingSwitch : public Actuator, public QGraphicsItem
{
public:
    LightingSwitch();
    LightingSwitch(QPoint a, QPoint b, int id);
    int turnLightOn;
    int turnLightOff;


private:
    QPixmap blackRoom;
    QPoint point1;
    QPoint point2;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // LIGHTINGSWITCH_H
