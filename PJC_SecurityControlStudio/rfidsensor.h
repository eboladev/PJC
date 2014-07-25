#ifndef RFIDSENSOR_H
#define RFIDSENSOR_H

#include "sensor.h"
#include "mobileobject.h"

class RfidSensor : public Sensor
{
public:
    RfidSensor();
    RfidSensor(QPoint a, QPoint b, int id);

private:
    int objectValidation;
    int intruderDetected;
    QPoint point1;
    QPoint point2;

public slots:
    void detect(MobileObject *movingObject1);
};

#endif // RFIDSENSOR_H
