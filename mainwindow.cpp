#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "waypoint.h"
#include <QPainter>
#include <QMouseEvent>
#include <QtGlobal>
#include <QMessageBox>
#include <QTimer>
#include <QXmlStreamReader>
#include <QtDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateMap()));
    timer->start(10);

    // 设置100ms后游戏启动
    //QTimer::singleShot(100, this, SLOT(gameStart()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadTowerPositions()
{
    QFile file(":/config/TowersPosition.plist");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "TowerDefense", "Cannot Open TowersPosition.plist");
        return;
    }




    foreach (QVariant dict, array)
    {
        QMap<QString, QVariant> point = dict.toMap();
        int x = point.value("x").toInt();
        int y = point.value("y").toInt();
        m_towerPositionsList.push_back(QPoint(x, y));
    }

    file.close();
}


