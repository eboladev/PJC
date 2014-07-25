#ifndef ALARM_H
#define ALARM_H

#include "actuator.h"
#include <QObject>
#include <QSound>
#include <QSoundEffect>


class Alarm : public Actuator
{
public:
    Alarm();
    Alarm(int id);
    int turnAlarmOn;
    int turnAlarmOff;
    bool intruderDetecionFlag;
    void playSound();

private:
    QSoundEffect effect;

};

#endif // ALARM_H
