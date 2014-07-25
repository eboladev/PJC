#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //sfiksowane rozmiary
    this->setFixedSize(this->geometry().width(),this->geometry().height());
    myScene = new QGraphicsScene(this);
    ui->graphicsView->setScene(myScene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    myScene->setSceneRect(0,0,800,600);
    ui->graphicsView->setSceneRect(myScene->sceneRect());
    startFlag = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refresh(){

    mySystem->myRobot->pathPlanning();
    mySystem->myRobot->move();
    mySystem->myEmployee->pathPlanning();
    mySystem->myEmployee->move();

    mySystem->myMotionSensor[0]->detect(mySystem->myRobot, mySystem->myEmployee, myIntruder);
    mySystem->myMotionSensor[1]->detect(mySystem->myRobot, mySystem->myEmployee, myIntruder);
    mySystem->myMotionSensor[2]->detect(mySystem->myRobot, mySystem->myEmployee, myIntruder);
    mySystem->myMotionSensor[3]->detect(mySystem->myRobot, mySystem->myEmployee, myIntruder);
    mySystem->myMotionSensor[4]->detect(mySystem->myRobot, mySystem->myEmployee, myIntruder);
    mySystem->myMotionSensor[5]->detect(mySystem->myRobot, mySystem->myEmployee, myIntruder);
    mySystem->myMotionSensor[6]->detect(mySystem->myRobot, mySystem->myEmployee, myIntruder);

    mySystem->myRfidSensor[0]->detect(mySystem->myRobot);
    mySystem->myRfidSensor[1]->detect(mySystem->myRobot);
    mySystem->myRfidSensor[0]->detect(mySystem->myEmployee);
    mySystem->myRfidSensor[1]->detect(mySystem->myEmployee);
    mySystem->myRfidSensor[0]->detect(myIntruder);
    mySystem->myRfidSensor[1]->detect(myIntruder);

    mySystem->myContacton[0]->detect(mySystem->myDoorActuator[0]);
    mySystem->myContacton[1]->detect(mySystem->myDoorActuator[1]);

    //mySystem->myRobot->faceRecognition(myIntruder);


    myIntruder->pathPlanning();

    myIntruder->move();

    mySystem->getData();
    mySystem->sendData();

    myScene->update();
}

void MainWindow::refresh2(){
    mySystem->myAlarm->playSound();
}

void MainWindow::startSimulation(){
    myMap = new Map;

    mySystem = new SystemSecurity(myMap);

    myIntruder = new Intruder;

    mySystem->myRobot->myKeyPoint = myMap->kps[0];
    myIntruder->myKeyPoint = myMap->kps[30];//30
    mySystem->myEmployee->myKeyPoint = myMap->kps[16];

    myScene->addItem(myMap);
    myScene->addItem(myIntruder);
    myScene->addItem(mySystem->myRobot);
    myScene->addItem(mySystem->myEmployee);
    myScene->addItem(mySystem->mySwitch[0]);
    myScene->addItem(mySystem->mySwitch[1]);
    myScene->addItem(mySystem->mySwitch[2]);
    myScene->addItem(mySystem->mySwitch[3]);
    myScene->addItem(mySystem->mySwitch[4]);
    myScene->addItem(mySystem->mySwitch[5]);
    myScene->addItem(mySystem->mySwitch[6]);
    myScene->addItem(mySystem->myDoorActuator[0]);
    myScene->addItem(mySystem->myDoorActuator[1]);

    myTimer = new QTimer(this);
    connect(myTimer, SIGNAL(timeout()), this, SLOT(refresh()));
    myTimer->start(8);

    myTimer2 = new QTimer(this);
    connect(myTimer2, SIGNAL(timeout()), this, SLOT(refresh2()));
    myTimer2->start(200);

}

void MainWindow::endSimulation(){
    myScene->removeItem(myMap);
    myScene->removeItem(myIntruder);
    myScene->removeItem(mySystem->myRobot);
    myScene->removeItem(mySystem->myEmployee);
    myScene->removeItem(mySystem->mySwitch[0]);
    myScene->removeItem(mySystem->mySwitch[1]);
    myScene->removeItem(mySystem->mySwitch[2]);
    myScene->removeItem(mySystem->mySwitch[3]);
    myScene->removeItem(mySystem->mySwitch[4]);
    myScene->removeItem(mySystem->mySwitch[5]);
    myScene->removeItem(mySystem->mySwitch[6]);
    myScene->removeItem(mySystem->myDoorActuator[0]);
    myScene->removeItem(mySystem->myDoorActuator[1]);
    delete myTimer;
    delete myTimer2;

}

void MainWindow::on_startButton_clicked()
{
    if(!startFlag) {
        this->startSimulation();
        startFlag = 1;
    }
}

void MainWindow::on_cancelButton_clicked()
{
    if(startFlag) {

        this->endSimulation();
        startFlag = 0;
    }
}
