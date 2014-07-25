#include "keypoint.h"


KeyPoint::KeyPoint()
{

}

KeyPoint::KeyPoint(int x, int y)
{
    p.setX(x);
    p.setY(y);
}

void KeyPoint::addConnection(KeyPoint *point)
{
    pnt_keyPoints.push_back(point);
}

void KeyPoint::deleteConnection(KeyPoint *point)
{
    for(int i=0; i<pnt_keyPoints.length(); i++){
        if(pnt_keyPoints[i]->p.x() == point->p.x() && pnt_keyPoints[i]->p.y() == point->p.y())
            pnt_keyPoints.remove(i);
    }
}
