#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "towerposition.h"
#include"waypoint.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class WayPoint;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void loadTowerPositions();
    void addWayPoints();

private:
    Ui::MainWindow *ui;
    QList<TowerPosition>	m_towerPositionsList;
    QList<WayPoint *>		m_wayPointsList;
};
#endif // MAINWINDOW_H
