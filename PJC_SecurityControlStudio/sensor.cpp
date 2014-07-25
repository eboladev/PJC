#include "sensor.h"

Sensor::Sensor(QObject *parent) :
    QObject(parent)
{
}

void Sensor::sendData(int address, int dataRegister){
    //qDebug()<<"signal works";
    //if(dataRegister==100) qDebug()<<"motionDetected";
    sensorAddress = address;
    sensorData = dataRegister;
}

