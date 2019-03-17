#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDateTime>
#include <QTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString starttime ="2015-02-28 12:00:00";
    QString endtime = "2015-03-01 12:00:00";

    QDateTime start = QDateTime::fromString(starttime, "yyyy-MM-dd hh:mm:ss");
    QDateTime end = QDateTime::fromString(endtime, "yyyy-MM-dd hh:mm:ss");

    long long stime =  start.toTime_t();
    long long etime = end.toTime_t();

    qDebug() << "starttime" << starttime;
    qDebug() << "endtime" << endtime;
    qDebug() << "....................................";

    qDebug() << "etime" << etime;
    qDebug() << "stime" << stime;
    qDebug() << "etime - stime" << etime - stime;

    long long  ndaysec = 24*60*60; //转换成秒
    qDebug() << "Day = " << (etime - stime)/(ndaysec) +
                ((etime - stime)%(ndaysec)+(ndaysec -1))/(ndaysec) -1;

    qDebug() << start.daysTo(end);//QDateTime 有函数可以直接运算
    /***
     * starttime "2017-11-11 12:00:00"
     * endtime "2017-11-13 12:00:00"
     * ....................................
     * etime 1510545600
     * stime 1510372800
     * etime - stime 172800
     * Day =  1
     * */
}

MainWindow::~MainWindow()
{
    delete ui;
}
