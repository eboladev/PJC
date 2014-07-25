#include "contactron.h"

Contactron::Contactron()
{
}

Contactron::Contactron(int id){
    sensorAddress = id;
    isOpened = 111;
    isClosed = 110;
    sensorData = isOpened;
}

void Contactron::detect(Actuator *actuator){
    if(actuator->actuatorAddress == this->sensorAddress + 100)
    {
        if(actuator->actuatorData == isOpened + 100)
        sensorData = isOpened;
        if(actuator->actuatorData == isClosed + 100)
        sensorData = isClosed;
    }
}
