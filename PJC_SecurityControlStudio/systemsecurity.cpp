#include "systemsecurity.h"

SystemSecurity::SystemSecurity(Map *map, QObject *parent) :
    QObject(parent)
{
    myMap = map;
    //definicja dynamicznych obiektow-aktuatorow -> sterowanie swiatlem
    this->mySwitch[0] = new LightingSwitch(QPoint(45,50),QPoint(275,138),200);
    this->mySwitch[1] = new LightingSwitch(QPoint(322,50),QPoint(270,138),201);
    this->mySwitch[2] = new LightingSwitch(QPoint(45,240),QPoint(277,207),202);
    this->mySwitch[3] = new LightingSwitch(QPoint(322,240),QPoint(205,207),203);
    this->mySwitch[4] = new LightingSwitch(QPoint(45,493),QPoint(277,65),204);
    this->mySwitch[5] = new LightingSwitch(QPoint(322,493),QPoint(205,65),205);
    this->mySwitch[6] = new LightingSwitch(QPoint(590,50),QPoint(162,505),206);

    //definicja dynamicznych obiektow-sensorow -> czujnik ruchu
    this->myMotionSensor[0] = new MotionSensor(QPoint(45,50),QPoint(275,138),100);
    this->myMotionSensor[1] = new MotionSensor(QPoint(322,50),QPoint(270,138),101);
    this->myMotionSensor[2] = new MotionSensor(QPoint(45,240),QPoint(277,207),102);
    this->myMotionSensor[3] = new MotionSensor(QPoint(322,240),QPoint(205,207),103);
    this->myMotionSensor[4] = new MotionSensor(QPoint(45,493),QPoint(277,65),104);
    this->myMotionSensor[5] = new MotionSensor(QPoint(322,493),QPoint(205,65),105);
    this->myMotionSensor[6] = new MotionSensor(QPoint(590,50),QPoint(162,505),106);

    //definicja dynamicznych obiektow-sensorow -> sensorow RFID
    this->myRfidSensor[0] = new RfidSensor(QPoint(322,240),QPoint(205,207),120);
    this->myRfidSensor[1] = new RfidSensor(QPoint(590,50),QPoint(162,505),121);

    //definicja dynamicznego obiektu-aktuator alarm
    this->myAlarm = new Alarm(220);

    //defincija dynamicznego obiektu-aktuator drzwi
    this->myDoorActuator[0] = new DoorActuator(QPoint(251,188),QPoint(45,5),210);
    this->myDoorActuator[1] = new DoorActuator(QPoint(537,188),QPoint(45,5),211);

    //definicja dynamicznego obiektu-sensor kontaktronow
    this->myContacton[0] = new Contactron(110);
    this->myContacton[1] = new Contactron(111);

    //definicja dynamicznego obiektu- robot
    this->myRobot = new Robot;

    //definicja dynamicznego obiektu- employee
    this->myEmployee = new Employee;

    //incjacja systemData
    systemData.push_back(QPoint(100,0));
    systemData.push_back(QPoint(101,0));
    systemData.push_back(QPoint(102,0));
    systemData.push_back(QPoint(103,0));
    systemData.push_back(QPoint(104,0));
    systemData.push_back(QPoint(105,0));
    systemData.push_back(QPoint(106,0));
    systemData.push_back(QPoint(110,0));
    systemData.push_back(QPoint(111,0));
    systemData.push_back(QPoint(120,0));
    systemData.push_back(QPoint(121,0));
    systemData.push_back(QPoint(200,200));
    systemData.push_back(QPoint(201,200));
    systemData.push_back(QPoint(202,200));
    systemData.push_back(QPoint(203,200));
    systemData.push_back(QPoint(204,200));
    systemData.push_back(QPoint(205,200));
    systemData.push_back(QPoint(206,200));
    systemData.push_back(QPoint(210,210));
    systemData.push_back(QPoint(211,210));
    systemData.push_back(QPoint(220,221));

}

void SystemSecurity::getData(){
    for(int i =0; i<7; i++)
    {
        if(systemData[i].x() == this->myMotionSensor[i]->sensorAddress)
        systemData[i].setY(this->myMotionSensor[i]->sensorData);
    }
    for(int i=7; i<9; i++)
    {
        if(systemData[i].x() == this->myContacton[i-7]->sensorAddress)
        systemData[i].setY(this->myContacton[i-7]->sensorData);
    }
    for(int i=9; i<11; i++)
    {
        if(systemData[i].x() == this->myRfidSensor[i-9]->sensorAddress)
        systemData[i].setY(this->myRfidSensor[i-9]->sensorData);
    }
}

void SystemSecurity::sendData(){
    for(int i =0; i<7; i++)
    {
        if(this->mySwitch[i]->actuatorAddress == systemData[i].x()+100)
        {
            this->mySwitch[i]->actuatorData = systemData[i].y()+100;
        }
    }
    for(int i=7; i<9; i++)
    {
        if(this->myAlarm->intruderDetecionFlag == true)
        {
            //ustawianie drzwi
            this->myDoorActuator[0]->actuatorData = this->myDoorActuator[0]->doorClose;
            this->myDoorActuator[1]->actuatorData = this->myDoorActuator[1]->doorClose;
            //usuwanie przejscia - obiekty nie mogą wybierac trajektori przez drzwi
            myMap->kps[1]->deleteConnection(myMap->kps[2]);
            myMap->kps[6]->deleteConnection(myMap->kps[7]);
            myMap->kps[2]->deleteConnection(myMap->kps[1]);
            myMap->kps[7]->deleteConnection(myMap->kps[6]);
        }
    }
    if(this->myAlarm->actuatorAddress == systemData[9].x()+100 &&
       this->myAlarm->actuatorAddress == systemData[10].x()+99)
    {
        if(systemData[9].y()+100 == myAlarm->turnAlarmOn ||
                this->myRobot->intruderDetected == true)
        {
            this->myAlarm->actuatorData = systemData[9].y()+100;
            this->myAlarm->intruderDetecionFlag = true;
            qDebug()<<"setting 1 to intrudetDetectionFlag";
        }
        if(systemData[10].y()+100 == myAlarm->turnAlarmOn ||
                this->myRobot->intruderDetected == true)
        {
            this->myAlarm->actuatorData = systemData[10].y()+100;
            this->myAlarm->intruderDetecionFlag = true;
            qDebug()<<"setting 1 to intrudetDetectionFlag";
        }
    }
}



