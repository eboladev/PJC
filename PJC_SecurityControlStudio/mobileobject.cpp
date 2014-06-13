#include "mobileobject.h"

MobileObject::MobileObject(QObject *parent) :
    QObject(parent)
{   
    changeDestinationFlag = 1;
}

void MobileObject::pathPlanning(){
    if(changeDestinationFlag)
    {
        qDebug()<<"0";
        std::random_shuffle(myKeyPoint->pnt_keyPoints.begin(),
                            myKeyPoint->pnt_keyPoints.end());
        qDebug()<<"1";
        myKeyPoint = myKeyPoint->pnt_keyPoints.first();
        qDebug()<<"2";
        changeDestinationFlag = 0;
        qDebug()<<"3";
    }
    destinationPoint =  myKeyPoint->p;
}

void MobileObject::move(){
    if(currentPositionPoint.x() < destinationPoint.x())
    {
        currentPositionPoint.setX(currentPositionPoint.x() + 1);
    }
    if(currentPositionPoint.x() > destinationPoint.x())
    {
        currentPositionPoint.setX(currentPositionPoint.x() - 1);
    }
    if(currentPositionPoint.y() < destinationPoint.y())
    {
        currentPositionPoint.setY(currentPositionPoint.y() + 1);
    }
    if(currentPositionPoint.y() > destinationPoint.y())
    {
        currentPositionPoint.setY(currentPositionPoint.y() - 1);
    }
    if((currentPositionPoint.x() == destinationPoint.x()) &&
        currentPositionPoint.y() == destinationPoint.y())
    {
        changeDestinationFlag = 1;
    }
}

void MobileObject::setSpeed(){

}
