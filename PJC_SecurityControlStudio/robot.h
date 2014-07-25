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
    void faceRecognition(MobileObject *intruder);
    bool intruderDetected;

private:
    QPixmap robotUp;
    QPixmap robotDown;
    QPixmap robotLeft;
    QPixmap robotRight;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ROBOT_H
