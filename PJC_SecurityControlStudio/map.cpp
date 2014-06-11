#include "map.h"

Map::Map()
{
    myPixmap.load(":/images/buildingMap2.png");

    //horizontal paths
    addPathPoints(70, 215, 560, 215);
    addPathPoints(70, 470, 560, 470);

    //vertical paths
    addPathPoints(560, 215, 560, 530);
}

QRectF Map::boundingRect() const
{
    return QRect(0,0,800,600);
}

void Map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,800,600,myPixmap);
    QPen myQPen = QPen(Qt::red);
    myQPen.setWidth(2);
    painter->setPen(myQPen);
}

void Map::addPathPoints(int x1, int y1, int x2, int y2)
{
    QPoint p;

    if(x1 == x2){
        if(y1<y2){
            for (int y=y1; y<=y2; y++){
                p.setX(x1);
                p.setY(y);
                if(!pathPoints.contains(p)) { pathPoints.push_back(p); }
            }
        }
        else{
            for (int y=y2; y<=y1; y++){
                p.setX(x1);
                p.setY(y);
                if(!pathPoints.contains(p)) { pathPoints.push_back(p); }
            }
        }
    }
    else{ //y1==y2
        if(x1<x2){
            for (int x=x1; x<=x2; x++){
                p.setX(x);
                p.setY(y1);
                if(!pathPoints.contains(p)) { pathPoints.push_back(p); }
            }
        }
        else{
            for (int x=x2; x<=x1; x++){
                p.setX(x);
                p.setY(y1);
                if(!pathPoints.contains(p)) { pathPoints.push_back(p); }
            }
        }
    }
}
