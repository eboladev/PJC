#include "robot.h"

Robot::Robot()
{
    currentPositionPoint.setX(70);
    currentPositionPoint.setY(215);
    destinationPoint.setX(560);
    destinationPoint.setY(215);
    robotDirection = 1;

    robotUp.load(":/images/robot1");
    robotRight.load(":/images/robot1");
    robotLeft.load(":/images/robot1");
    robotDown.load(":/images/robot1");

}

void Robot::catchIntruder(){

}

void Robot::sendData(){

}

void Robot::faceRecognition(){

}

QRectF Robot::boundingRect() const
{
    return QRectF(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30);
}

void Robot::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch(robotDirection){
    case 1:
        painter->drawPixmap(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30, robotUp);
    break;

    case 2:
        painter->drawPixmap(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30, robotLeft);
    break;

    case 3:
        painter->drawPixmap(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30, robotRight);
    break;

    case 4:
        painter->drawPixmap(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30, robotDown);
    break;
    }
}
