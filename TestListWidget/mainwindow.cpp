#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "checkboxbuttonwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int var = 0; var < 5; ++var) {

        CheckBoxButtonWidget * w = new CheckBoxButtonWidget("123"+QString("-%1").arg(var),ui->listWidget);

        QListWidgetItem * item = new QListWidgetItem(ui->listWidget);
        //item->setCheckState(Qt::Checked);
        item->setSizeHint(QSize(20, 50));


        ui->listWidget->setItemWidget(item, w);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
