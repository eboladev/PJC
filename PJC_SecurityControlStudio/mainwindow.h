#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "map.h"

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

private slots:
    void on_startButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::MainWindow *ui;
    Map *myMap;
    QGraphicsScene *myScene;
    
};

#endif // MAINWINDOW_H
