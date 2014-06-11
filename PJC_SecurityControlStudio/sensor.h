#ifndef SENSOR_H
#define SENSOR_H

#include <QObject>

class Sensor : public QObject
{
    Q_OBJECT
public:
    explicit Sensor(QObject *parent = 0);
    void sendData(int address, int dataRegister);

private:
    int sensorID;
    void getReading();

signals:

public slots:

};

#endif // SENSOR_H
