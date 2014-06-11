#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //myMap = new Map;

    ui->setupUi(this);
    //sfiksowane rozmiary
    this->setFixedSize(this->geometry().width(),this->geometry().height());
    myScene = new QGraphicsScene(this);
    ui->graphicsView->setScene(myScene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    myScene->setSceneRect(0,0,800,600);
    ui->graphicsView->setSceneRect(myScene->sceneRect());
    //myScene->addItem(myMap);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startSimulation(){
    myMap = new Map;
    myScene->addItem(myMap);
    //myScene->addText("ffgfdgdf");
}

void MainWindow::endSimulation(){

}

void MainWindow::on_startButton_clicked()
{
    this->startSimulation();
}

void MainWindow::on_cancelButton_clicked()
{
    this->endSimulation();
}
