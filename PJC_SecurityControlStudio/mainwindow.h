#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include "map.h"
#include "robot.h"

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

private slots:
    void on_startButton_clicked();
    void on_cancelButton_clicked();
    void refresh();

private:
    Ui::MainWindow *ui;
    Map *myMap;
    Robot *myRobot;
    QGraphicsScene *myScene;

    
};

#endif // MAINWINDOW_H
