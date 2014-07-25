#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "mobileobject.h"

class Employee : public MobileObject
{
public:
    Employee();


private:
    void escape();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPixmap workerUp;
    QPixmap workerDown;
    QPixmap workerLeft;
    QPixmap workerRight;
};

#endif // EMPLOYEE_H
