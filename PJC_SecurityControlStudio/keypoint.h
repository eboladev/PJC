#ifndef KEYPOINT_H
#define KEYPOINT_H

#include <QVector>
#include <QPoint>

class KeyPoint
{
public:
    KeyPoint();
    KeyPoint(int x, int y);
    QPoint p;
    QVector <KeyPoint*> pnt_keyPoints;

    void addConnection(KeyPoint *point);
    void deleteConnection(KeyPoint *point);
};

#endif // KEYPOINT_H
