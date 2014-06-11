#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "mobileobject.h"

class Employee : public MobileObject
{
public:
    Employee();

private:
    void sendData();
    void escape();
};

#endif // EMPLOYEE_H
