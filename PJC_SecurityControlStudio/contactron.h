#ifndef CONTACTRON_H
#define CONTACTRON_H

#include "sensor.h"
#include "mobileobject.h"
#include "actuator.h"

class Contactron : public Sensor
{
public:
    Contactron();
    Contactron(int id);
    int isOpened;
    int isClosed;
    void detect(Actuator *actuator);

private:
    QPoint point1;
    QPoint point2;

};

#endif // CONTACTRON_H
