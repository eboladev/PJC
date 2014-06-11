#ifndef MAP_H
#define MAP_H

#include <QGraphicsItem>
#include <QPainter>
#include <QVector>
#include <QGraphicsScene>

class Map : public QGraphicsItem
{
public:
    Map();
    //trzeba zdefiniowac funckje wirtualne aby moc utworzyc obiekty klasy
    //dziedziczacej po klasie wirtualnej
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


private:
    QPixmap myPixmap;
    QVector <QPoint> pathPoints;
    void addPathPoints(int x1, int y1, int x2, int y2);

};

#endif // MAP_H
