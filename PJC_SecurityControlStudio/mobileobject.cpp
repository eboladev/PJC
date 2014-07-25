#include "mobileobject.h"

MobileObject::MobileObject(QObject *parent) :
    QObject(parent)
{   
    changeDestinationFlag = 1;
}

void MobileObject::pathPlanning(){
    if(changeDestinationFlag)
    {
        //qDebug()<<"executing pathPlanning";
        std::random_shuffle(myKeyPoint->pnt_keyPoints.begin(),
                            myKeyPoint->pnt_keyPoints.end());
        myKeyPoint = myKeyPoint->pnt_keyPoints.first();
        changeDestinationFlag = 0;
        destinationPoint =  myKeyPoint->p;

        if(currentPositionPoint.x() < destinationPoint.x())
        {
            movingDirection = 2; //left
        }

        else if(currentPositionPoint.x() > destinationPoint.x())
        {
            movingDirection = 1; //right
        }

        else if(currentPositionPoint.y() < destinationPoint.y())
        {
            movingDirection = 3; //up
        }

        else if(currentPositionPoint.y() > destinationPoint.y())
        {
            movingDirection = 0; //down
        }

        //qDebug()<<"movingDirection = "<< movingDirection;
     }
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

