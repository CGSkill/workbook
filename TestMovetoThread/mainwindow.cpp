#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    test = new Test();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QVariant v(QString("1231231312"));
    test->setData(v);

    qDebug()<< "####################" <<QThread::currentThreadId();
    QThread *t = new QThread();
    test->moveToThread(t);
    connect(t, SIGNAL(started()), test, SLOT(fortest()));

    t->start();
    qDebug()<< "@@@@@@@@@@@@@@@@@@@@@@@@" <<t->currentThreadId();
    qDebug()<< "####################" <<QThread::currentThreadId();
}
