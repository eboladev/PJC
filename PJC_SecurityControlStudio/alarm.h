#ifndef ALARM_H
#define ALARM_H

#include "actuator.h"

class Alarm : public Actuator
{
public:
    Alarm();

private:
    void playSound();

};

#endif // ALARM_H
