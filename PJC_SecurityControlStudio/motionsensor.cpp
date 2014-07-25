#include "motionsensor.h"

MotionSensor::MotionSensor()
{

}

MotionSensor::MotionSensor(QPoint a, QPoint b, int id)
{
    motionDetected = 100; //rejestr danych
    motionNotDetected = 101; //rejestr danych
    point1 = a;
    point2 = b;
    sensorAddress = id;
    connect(this, SIGNAL(detect(MobileObject*)), this, SLOT(sendData(int,int)));
}

void MotionSensor::detect(MobileObject *movingObject1, MobileObject *movingObject2, MobileObject *movingObject3){

    if((movingObject1->currentPositionPoint.x() > point1.x()
      && movingObject1->currentPositionPoint.y() > point1.y()
      && movingObject1->currentPositionPoint.x() < point1.x() + point2.x()
      && movingObject1->currentPositionPoint.y() < point1.y() + point2.y())
    || (movingObject2->currentPositionPoint.x() > point1.x()
        && movingObject2->currentPositionPoint.y() > point1.y()
        && movingObject2->currentPositionPoint.x() < point1.x() + point2.x()
        && movingObject2->currentPositionPoint.y() < point1.y() + point2.y())
    || (movingObject3->currentPositionPoint.x() > point1.x()
        && movingObject3->currentPositionPoint.y() > point1.y()
        && movingObject3->currentPositionPoint.x() < point1.x() + point2.x()
        && movingObject3->currentPositionPoint.y() < point1.y() + point2.y()))
    {
        emit sendData(sensorAddress, motionDetected);
        //qDebug()<<"motion detected";
    }
    else
    {
        emit sendData(sensorAddress, motionNotDetected);
        //qDebug()<<"motion not detected";
    }
}

