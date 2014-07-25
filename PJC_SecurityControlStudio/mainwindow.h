#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include "map.h"
#include "robot.h"
#include "intruder.h"
#include "employee.h"
#include "systemsecurity.h"
#include "motionsensor.h"
#include "lightingswitch.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void startSimulation();
    void endSimulation();
    QTimer *myTimer;
    QTimer *myTimer2;

private slots:
    void on_startButton_clicked();
    void on_cancelButton_clicked();
    void refresh();
    void refresh2();

private:
    Ui::MainWindow *ui;
    Map *myMap;
    Intruder *myIntruder;
    SystemSecurity *mySystem;
    bool startFlag;
    QGraphicsScene *myScene;

    
};

#endif // MAINWINDOW_H
