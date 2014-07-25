#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QVector>
#include <QGraphicsScene>

class Actuator : public QObject
{
    Q_OBJECT
public:
    explicit Actuator(QObject *parent = 0);
    int actuatorAddress;
    int actuatorData;

private:



};

#endif // ACTUATOR_H
