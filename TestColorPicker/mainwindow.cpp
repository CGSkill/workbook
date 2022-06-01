#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TransparentForMouseEvents,true);
    setWindowFlags(Qt::WindowStaysOnTopHint  | Qt::Tool);

    time = new QTimer(this);
    connect(time,SIGNAL(timeout()),this, SLOT(showColor()));
    time->start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showColorValue(int x, int y)
{

    //输出坐标
    ui->lineEditCoordinate->setText(tr("x:%1  y:%2").arg(x).arg(y));

    //获取坐标像素点
    QWindow window;
    QPixmap pixmap = window.screen()->grabWindow(QApplication::desktop()->winId(),x,y,1,1);

    //获取像素点RGB
    int red, green, blue;
    if(!pixmap.isNull())
    {
        QImage image = pixmap.toImage();

        if(!image.isNull())
        {
            QColor color = image.pixel(0,0);
            red = color.red();
            green = color.green();
            blue = color.blue();

            //输出16进制的颜色
            QString hRed = QString::number(red,16).toUpper();
            QString hGreen = QString::number(green,16).toUpper();
            QString hBlue = QString::number(blue,16).toUpper();
            ui->lineEditHex->setText(tr("#%1%2%3").arg(hRed,2,QLatin1Char('0')).arg(hGreen,2,QLatin1Char('0')).arg(hBlue,2,QLatin1Char('0')));

            //输出RGB
            ui->lineEditRGB->setText(tr("R:%1 G:%2 B:%3").arg(red).arg(green).arg(blue));

            int width =ui->labelColorDisplay->width();
            int height = ui->labelColorDisplay->height();
            QPixmap labelPix(width,height);
            labelPix.fill(color);
            ui->labelColorDisplay->setPixmap(labelPix);
        }

        //设置label标签的颜色显示
    }
}

void MainWindow::showColor()
{
    showColorValue(QCursor::pos().x(),QCursor::pos().y());
}

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
    showColorValue(QCursor::pos().x(),QCursor::pos().y());
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
    showColorValue(QCursor::pos().x(),QCursor::pos().y());
}

