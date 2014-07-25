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
    QVector <QPoint> pathPoints;
    KeyPoint *kps[32];

private:
    QPixmap myPixmap;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // MAP_H
