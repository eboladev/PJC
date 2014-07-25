#include "employee.h"

Employee::Employee()
{
    currentPositionPoint.setX(615);
    currentPositionPoint.setY(80);
    destinationPoint.setX(560);
    destinationPoint.setY(215);

    movingDirection = 1;

    workerUp.load(":/images/workerUp");
    workerRight.load(":/images/workerRight");
    workerLeft.load(":/images/workerLeft");
    workerDown.load(":/images/workerDown");

    isIdOwner = true;
}


void Employee::escape(){

}

QRectF Employee::boundingRect() const
{
    return QRectF(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30);
}

void Employee::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch(this->movingDirection){
    case 0:
        painter->drawPixmap(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30, workerUp);
    break;

    case 1:
        painter->drawPixmap(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30, workerLeft);
    break;

    case 2:
        painter->drawPixmap(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30, workerRight);
    break;

    case 3:
        painter->drawPixmap(currentPositionPoint.x()-15,currentPositionPoint.y()-15,30,30, workerDown);
    break;
    }
}
