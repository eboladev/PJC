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

void KeyPoint::deleteConnection()
{

}
