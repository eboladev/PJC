#ifndef SYSTEMSECURITY_H
#define SYSTEMSECURITY_H

#include <QObject>
#include <QVector>
#include "sensor.h"
#include "actuator.h"
#include "alarm.h"
#include "dooractuator.h"
#include "lightingswitch.h"
#include "motionsensor.h"
#include "rfidsensor.h"
#include "contactron.h"
#include "robot.h"
#include "employee.h"
#include "map.h"

class SystemSecurity : public QObject
{
    Q_OBJECT
public:
    explicit SystemSecurity(Map *map, QObject *parent = 0);

    LightingSwitch *mySwitch[7];
    MotionSensor *myMotionSensor[7];
    Contactron *myContacton[2];
    RfidSensor *myRfidSensor[2];
    Alarm *myAlarm;
    DoorActuator *myDoorActuator[2];
    Robot *myRobot;
    Employee *myEmployee;
    Map *myMap;

    QList<QPoint> systemData;

public slots:
    void getData();
    void sendData();
};

#endif // SYSTEMSECURITY_H
