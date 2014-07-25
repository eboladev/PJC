#include "intruder.h"

Intruder::Intruder()
{
    currentPositionPoint.setX(70);//70
    currentPositionPoint.setY(270);//270
    destinationPoint.setX(560);
    destinationPoint.setY(215);

    intruderDirection = 1;

    intruderUp.load(":/images/intruderUp");
    intruderRight.load(":/images/intruderRight");
    intruderLeft.load(":/images/intruderLeft");
    intruderDown.load(":/images/intruderDown");

    isIdOwner = false;
}

/*void Intruder::hide(){ //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
    if(changeDestinationFlag)
    {
        //qDebug()<<"executing pathPlanning";
        KeyPoint *temp;
        for(int i=0; i<myKeyPoint->pnt_keyPoints.length(); i++)
        {
            if(currentPositionPoint.x() > myKeyPoint->pnt_keyPoints[i]->p.x()
               && currentPositionPoint.y() < myKeyPoint->pnt_keyPoints[i]->p.y())
            {
                temp = myKeyPoint->pnt_keyPoints[i];
                myKeyPoint->pnt_keyPoints[i] = myKeyPoint->pnt_keyPoints[i-1];
                myKeyPoint->pnt_keyPoints[i-1] = temp;
            }
        }
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

}*/

QRectF Intruder::boundingRect() const
{
    return QRectF(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30);
}

void Intruder::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch(this->movingDirection){
    case 0:
        painter->drawPixmap(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30, intruderUp);
    break;

    case 1:
        painter->drawPixmap(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30, intruderLeft);
    break;

    case 2:
        painter->drawPixmap(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30, intruderRight);
    break;

    case 3:
        painter->drawPixmap(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30, intruderDown);
    break;
    }
}
