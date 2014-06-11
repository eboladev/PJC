#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

#include "sensor.h"

class MotionSensor : public Sensor
{
public:
    MotionSensor();

private:
    bool motionDetected;
};

#endif // MOTIONSENSOR_H
