#ifndef DOORACTUATOR_H
#define DOORACTUATOR_H

#include "actuator.h"

class DoorActuator : public Actuator
{
public:
    DoorActuator();

private:
    void actuateDoor(int doorID);
};

#endif // DOORACTUATOR_H
