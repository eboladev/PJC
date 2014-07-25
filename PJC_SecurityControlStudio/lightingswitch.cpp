#include "lightingswitch.h"

LightingSwitch::LightingSwitch()
{

}

LightingSwitch::LightingSwitch(QPoint a, QPoint b, int id)
{
    point1 = a;
    point2 = b;
    actuatorAddress = id;
    blackRoom.load(":/images/black");
    turnLightOff = 201;
    turnLightOn = 200;
}

QRectF LightingSwitch::boundingRect() const
{
    return QRectF(point1.x(),point1.y(),point2.x(),point2.y());
}

void LightingSwitch::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(this->actuatorData == turnLightOff)
    {
        painter->drawPixmap(point1.x(),point1.y(),point2.x(),point2.y(), blackRoom);
    }
    if(this->actuatorData == turnLightOn)
    {

    }
}
