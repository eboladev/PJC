#ifndef ROBOT_H
#define ROBOT_H

#include "mobileobject.h"
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QVector>

class Robot : public MobileObject
{
public:
    Robot();
    void sendData();
    void catchIntruder();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int robotDirection;


private:
    bool intruderDetected;
    void faceRecognition();

    QPixmap robotUp;
    QPixmap robotDown;
    QPixmap robotLeft;
    QPixmap robotRight;
};

#endif // ROBOT_H
