#ifndef SENSOR_H
#define SENSOR_H

#include <QObject>
#include <QPoint>
#include <QDebug>
//#include "system.h"


class Sensor : public QObject
{
    Q_OBJECT
public:
    explicit Sensor(QObject *parent = 0);
    int sensorAddress;
    int sensorData;
private:

signals:

public slots:
    void sendData(int address, int dataRegister);

};

#endif // SENSOR_H
