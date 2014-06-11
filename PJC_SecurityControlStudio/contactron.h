#ifndef CONTACTRON_H
#define CONTACTRON_H

#include "sensor.h"

class Contactron : public Sensor
{
public:
    Contactron();

private:
    bool isOpened;
};

#endif // CONTACTRON_H
