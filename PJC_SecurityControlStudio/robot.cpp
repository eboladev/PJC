#include "robot.h"

Robot::Robot()
{
    currentPositionPoint.setX(70);//70
    currentPositionPoint.setY(215);//215
    destinationPoint.setX(560);
    destinationPoint.setY(215);

    movingDirection = 1;

    robotUp.load(":/images/robot1");
    robotRight.load(":/images/robot1");
    robotLeft.load(":/images/robot1");
    robotDown.load(":/images/robot1");

    isIdOwner = true;
}


void Robot::faceRecognition(MobileObject *intruder){
    if(this->currentPositionPoint.x() + 2     > intruder->currentPositionPoint.x()
        && this->currentPositionPoint.x() - 2 < intruder->currentPositionPoint.x()
        && this->currentPositionPoint.y() + 2 > intruder->currentPositionPoint.y()
        && this->currentPositionPoint.y() - 2 < intruder->currentPositionPoint.y())
        intruderDetected = true;
}

QRectF Robot::boundingRect() const
{
    return QRectF(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30);
}

void Robot::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch(this->movingDirection){
    case 0:
        painter->drawPixmap(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30, robotUp);
    break;

    case 1:
        painter->drawPixmap(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30, robotLeft);
    break;

    case 2:
        painter->drawPixmap(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30, robotRight);
    break;

    case 3:
        painter->drawPixmap(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30, robotDown);
    break;
    }
}
