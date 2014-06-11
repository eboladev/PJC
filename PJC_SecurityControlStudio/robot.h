#ifndef ROBOT_H
#define ROBOT_H

#include "mobileobject.h"

class Robot : public MobileObject
{
public:
    Robot();
    void sendData();
    void catchIntruder();

private:
    bool intruderDetected;
    void faceRecognition();
};

#endif // ROBOT_H
