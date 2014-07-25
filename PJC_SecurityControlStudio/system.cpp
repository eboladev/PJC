#include "systemsecurity.h"

System::System(QObject *parent) :
    QObject(parent)
{
    this->mySwitch[0] = new LightingSwitch(QPoint(45,50),QPoint(275,138),1);
    this->mySwitch[1] = new LightingSwitch(QPoint(322,50),QPoint(270,138),2);
    this->mySwitch[2] = new LightingSwitch(QPoint(45,240),QPoint(277,207),3);
    this->mySwitch[3] = new LightingSwitch(QPoint(322,240),QPoint(205,207),4);
    this->mySwitch[4] = new LightingSwitch(QPoint(45,493),QPoint(277,65),5);
    this->mySwitch[5] = new LightingSwitch(QPoint(322,493),QPoint(205,65),6);
    this->mySwitch[6] = new LightingSwitch(QPoint(590,50),QPoint(162,505),7);
    this->myMotionSensor[0] = new MotionSensor(QPoint(45,50),QPoint(275,138),100);
    //connect(this->myMotionSensor[0],SIGNAL())
}

void System::getData(int address, int data){

}

void System::ssendData(int address, int data){

}
