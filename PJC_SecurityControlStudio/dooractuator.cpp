#include "dooractuator.h"


DoorActuator::DoorActuator()
{
}

DoorActuator::DoorActuator(QPoint a, QPoint b, int id){
    point1 = a;
    point2 = b;
    actuatorAddress = id;
    door.load(":/images/door");
    doorClose = 210;
    doorOpen = 211;
    actuatorData = 211;
}

QRectF DoorActuator::boundingRect() const
{
    return QRectF(point1.x(),point1.y(),point2.x(),point2.y());
}

void DoorActuator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(this->actuatorData == doorClose)
    {
        painter->drawPixmap(point1.x(),point1.y(),point2.x(),point2.y(), door);
    }
    if(this->actuatorData == doorOpen)
    {

    }
}
