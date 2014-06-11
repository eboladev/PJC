#ifndef MOBILEOBJECT_H
#define MOBILEOBJECT_H

#include <QObject>

class MobileObject : public QObject
{
    Q_OBJECT
public:
    explicit MobileObject(QObject *parent = 0);
    void pathPlanning();
    void setSpeed();

private:
    bool isIdOwner;
    double posX;
    double posY;
    double speed;
    int mobileObjectID;

signals:

public slots:

};

#endif // MOBILEOBJECT_H
