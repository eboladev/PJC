#include "alarm.h"

Alarm::Alarm()
{
}

Alarm::Alarm(int id){
    actuatorAddress = id;
    turnAlarmOff = 221;
    turnAlarmOn = 220;
    intruderDetecionFlag = false;
    effect.setSource(QUrl::fromLocalFile("/home/tomziom/workspace/PJC_SecurityControlStudio/PJC_SecurityControlStudio/sounds/buzz.wav"));
    //effect.setLoopCount(QSoundEffect::Infinite);
    //effect.setVolume(1f);
}

void Alarm::playSound()
{
    if(intruderDetecionFlag)
    effect.play();
}

