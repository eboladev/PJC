#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

#include "sensor.h"
#include "mobileobject.h"

class MotionSensor : public Sensor
{
public:
    MotionSensor();
    MotionSensor(QPoint a, QPoint b, int id);

    int motionDetected;
    int motionNotDetected;

public slots:
    void detect(MobileObject *movingObject1, MobileObject *movingObject2, MobileObject *movingObject3);

private:
    QPoint point1;
    QPoint point2;

};

#endif // MOTIONSENSOR_H
