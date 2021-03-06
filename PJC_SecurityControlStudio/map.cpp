#include "map.h"

Map::Map()
{
    myPixmap.load(":/images/buildingMap2.png");

    kps[0] = new KeyPoint(70, 215);
    kps[1] = new KeyPoint(270, 215);
    kps[2] = new KeyPoint(270, 165);
    kps[3] = new KeyPoint(270, 80);
    kps[4] = new KeyPoint(70, 80);
    kps[5] = new KeyPoint(70, 165);
    kps[6] = new KeyPoint(560, 215);
    kps[7] = new KeyPoint(560, 165);
    kps[8] = new KeyPoint(560, 80);
    kps[9] = new KeyPoint(340, 80);
    kps[10] = new KeyPoint(340, 165);
    kps[11] = new KeyPoint(560, 472);
    kps[12] = new KeyPoint(560, 525);
    kps[13] = new KeyPoint(615, 472);
    kps[14] = new KeyPoint(730, 472);
    kps[15] = new KeyPoint(730, 80);
    kps[16] = new KeyPoint(615, 80);
    kps[17] = new KeyPoint(440, 472);
    kps[18] = new KeyPoint(440, 525);
    kps[19] = new KeyPoint(340, 525);
    kps[20] = new KeyPoint(440, 425);
    kps[21] = new KeyPoint(440, 270);
    kps[22] = new KeyPoint(341, 270);
    kps[23] = new KeyPoint(341, 425);
    kps[24] = new KeyPoint(200, 472);
    kps[25] = new KeyPoint(200, 525);
    kps[26] = new KeyPoint(70, 525);
    kps[27] = new KeyPoint(70, 472);
    kps[28] = new KeyPoint(200, 425);
    kps[29] = new KeyPoint(200, 270);
    kps[30] = new KeyPoint(70, 270);\
    kps[31] = new KeyPoint(70, 425);

    kps[0]->addConnection(kps[1]);
    kps[1]->addConnection(kps[0]);
    kps[1]->addConnection(kps[2]);
    kps[1]->addConnection(kps[6]);
    kps[2]->addConnection(kps[1]);
    kps[2]->addConnection(kps[3]);
    kps[2]->addConnection(kps[5]);
    kps[3]->addConnection(kps[2]);
    kps[3]->addConnection(kps[4]);
    kps[4]->addConnection(kps[3]);
    kps[4]->addConnection(kps[5]);
    kps[5]->addConnection(kps[4]);
    kps[5]->addConnection(kps[2]);
    kps[6]->addConnection(kps[1]);
    kps[6]->addConnection(kps[7]);
    kps[6]->addConnection(kps[11]);
    kps[7]->addConnection(kps[6]);
    kps[7]->addConnection(kps[8]);
    kps[7]->addConnection(kps[10]);
    kps[8]->addConnection(kps[7]);
    kps[8]->addConnection(kps[9]);
    kps[9]->addConnection(kps[8]);
    kps[9]->addConnection(kps[10]);
    kps[10]->addConnection(kps[7]);
    kps[10]->addConnection(kps[9]);
    kps[11]->addConnection(kps[6]);
    kps[11]->addConnection(kps[12]);
    kps[11]->addConnection(kps[13]);
    kps[11]->addConnection(kps[17]);
    kps[12]->addConnection(kps[11]);
    kps[13]->addConnection(kps[11]);
    kps[13]->addConnection(kps[14]);
    kps[13]->addConnection(kps[16]);
    kps[14]->addConnection(kps[13]);
    kps[14]->addConnection(kps[15]);
    kps[15]->addConnection(kps[14]);
    kps[15]->addConnection(kps[16]);
    kps[16]->addConnection(kps[15]);
    kps[16]->addConnection(kps[13]);
    kps[17]->addConnection(kps[11]);
    kps[17]->addConnection(kps[18]);
    kps[17]->addConnection(kps[20]);
    kps[17]->addConnection(kps[24]);
    kps[18]->addConnection(kps[17]);
    kps[18]->addConnection(kps[19]);
    kps[19]->addConnection(kps[18]);
    kps[20]->addConnection(kps[17]);
    kps[20]->addConnection(kps[21]);
    kps[20]->addConnection(kps[23]);
    kps[21]->addConnection(kps[20]);
    kps[21]->addConnection(kps[22]);
    kps[22]->addConnection(kps[21]);
    kps[22]->addConnection(kps[23]);
    kps[23]->addConnection(kps[22]);
    kps[23]->addConnection(kps[20]);
    kps[24]->addConnection(kps[17]);
    kps[24]->addConnection(kps[25]);
    kps[24]->addConnection(kps[28]);
    kps[24]->addConnection(kps[27]);
    kps[25]->addConnection(kps[24]);
    kps[25]->addConnection(kps[26]);
    kps[26]->addConnection(kps[25]);
    kps[27]->addConnection(kps[24]);
    kps[28]->addConnection(kps[24]);
    kps[28]->addConnection(kps[29]);
    kps[28]->addConnection(kps[31]);
    kps[29]->addConnection(kps[28]);
    kps[29]->addConnection(kps[30]);
    kps[30]->addConnection(kps[29]);
    kps[30]->addConnection(kps[31]);
    kps[31]->addConnection(kps[30]);
    kps[31]->addConnection(kps[28]);

    //horizontal paths
    //addPathPoints(70, 215, 560, 215);
    //addPathPoints(70, 470, 560, 470);

    //vertical paths
    //addPathPoints(560, 215, 560, 530);
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
/*
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
*/
