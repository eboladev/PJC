#ifndef MOBILEOBJECT_H
#define MOBILEOBJECT_H

#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QVector>
#include <QtCore>
//#include "mainwindow.h"
#include "keypoint.h"


class MobileObject : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MobileObject(QObject *parent = 0);
    void pathPlanning();
    void move();
    void setSpeed();
    QPoint currentPositionPoint;
    QPoint destinationPoint;
    QVector <QPoint> pathPoints;
    KeyPoint *myKeyPoint;
    bool changeDestinationFlag;

private:
    bool isIdOwner;
    double speed;
    int mobileObjectID;

signals:

public slots:

};

#endif // MOBILEOBJECT_H
