#ifndef LIGHTINGSWITCH_H
#define LIGHTINGSWITCH_H

#include "actuator.h"

class LightingSwitch : public Actuator
{
public:
    LightingSwitch();

private:
    void switchLight(int roomID);
};

#endif // LIGHTINGSWITCH_H
