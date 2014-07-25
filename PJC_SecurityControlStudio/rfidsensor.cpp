#include "rfidsensor.h"

RfidSensor::RfidSensor()
{
}

RfidSensor::RfidSensor(QPoint a, QPoint b, int id){
    intruderDetected = 120; //rejestr danych
    objectValidation = 121; //rejestr danych
    point1 = a;
    point2 = b;
    sensorAddress = id;
    connect(this, SIGNAL(detect(MobileObject*)), this, SLOT(sendData(int,int)));
}


void RfidSensor::detect(MobileObject *movingObject1){

    if(movingObject1->currentPositionPoint.x() > point1.x()
      && movingObject1->currentPositionPoint.y() > point1.y()
      && movingObject1->currentPositionPoint.x() < point1.x() + point2.x()
      && movingObject1->currentPositionPoint.y() < point1.y() + point2.y()
      && movingObject1->isIdOwner == false)
    {
        emit sendData(sensorAddress, intruderDetected);
        qDebug()<<"intruder detected!!!!";
    }
    else if(movingObject1->currentPositionPoint.x() > point1.x()
            && movingObject1->currentPositionPoint.y() > point1.y()
            && movingObject1->currentPositionPoint.x() < point1.x() + point2.x()
            && movingObject1->currentPositionPoint.y() < point1.y() + point2.y()
            && movingObject1->isIdOwner == true)
    {
        emit sendData(sensorAddress, objectValidation);
        qDebug()<<"object validated";
    }
}
