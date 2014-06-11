#ifndef RFIDSENSOR_H
#define RFIDSENSOR_H

#include "sensor.h"

class RfidSensor : public Sensor
{
public:
    RfidSensor();

private:
    bool intruderDetected;
};

#endif // RFIDSENSOR_H
