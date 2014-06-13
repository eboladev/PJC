#ifndef MAP_H
#define MAP_H

#include <QGraphicsItem>
#include <QPainter>
#include <QVector>
#include <QGraphicsScene>
#include "keypoint.h"


class Map : public QGraphicsItem
{
public:
    Map();
    //trzeba zdefiniowac funckje wirtualne aby moc utworzyc obiekty klasy
    //dziedziczacej po klasie wirtualnej
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QVector <QPoint> pathPoints;
    /*KeyPoint *kp1;
    KeyPoint *kp2;
    KeyPoint *kp3;
    KeyPoint *kp4;*/
    KeyPoint *kps[32];

private:
    QPixmap myPixmap;

    void addPathPoints(int x1, int y1, int x2, int y2);

};

#endif // MAP_H
