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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refresh(){
    myRobot->pathPlanning();
    myRobot->move();
    qDebug()<<myRobot->currentPositionPoint.x()<<"  "<<myRobot->currentPositionPoint.y();
    //refresh robot
    //refresh worker
    //refresh intruder
    //refresh lightONOFF
    //refresh doors
    //refresh alarm
    //ALBO REFRESH SYSTEM jeszcze nie wiem
    myScene->update();
}

void MainWindow::startSimulation(){
    myMap = new Map;
    myRobot = new Robot;
    myRobot->myKeyPoint = myMap->kps[0];
    myScene->addItem(myMap);
    myScene->addItem(myRobot);
    myTimer = new QTimer(this);
    connect(myTimer, SIGNAL(timeout()), this, SLOT(refresh()));
    myTimer->start(10); //30ms

}

void MainWindow::endSimulation(){
    myScene->removeItem(myRobot);
    myScene->removeItem(myMap);

}

void MainWindow::on_startButton_clicked()
{
    this->startSimulation();
}

void MainWindow::on_cancelButton_clicked()
{
    this->endSimulation();
}
