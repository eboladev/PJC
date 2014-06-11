#-------------------------------------------------
#
# Project created by QtCreator 2014-05-10T12:44:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PJC_SecurityControlStudio
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mobileobject.cpp \
    employee.cpp \
    robot.cpp \
    intruder.cpp \
    actuator.cpp \
    alarm.cpp \
    dooractuator.cpp \
    lightingswitch.cpp \
    sensor.cpp \
    motionsensor.cpp \
    rfidsensor.cpp \
    contactron.cpp \
    map.cpp

HEADERS  += mainwindow.h \
    mobileobject.h \
    employee.h \
    robot.h \
    intruder.h \
    actuator.h \
    alarm.h \
    dooractuator.h \
    lightingswitch.h \
    sensor.h \
    motionsensor.h \
    rfidsensor.h \
    contactron.h \
    map.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc \
    sounds.qrc
