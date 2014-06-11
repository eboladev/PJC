#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <QObject>

class Actuator : public QObject
{
    Q_OBJECT
public:
    explicit Actuator(QObject *parent = 0);
    void getData(int address, int dataRegister);

private:
    int actuatorID;

signals:

public slots:

};

#endif // ACTUATOR_H
