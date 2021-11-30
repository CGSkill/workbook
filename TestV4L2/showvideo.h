#ifndef SHOWVIDEO_H
#define SHOWVIDEO_H

#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QTimer>
#include <QPaintEvent>
#include <QHBoxLayout>
#include <QDebug>

#include "videodevice.h"


class showvideo : public QWidget
{
    Q_OBJECT
public:
    explicit showvideo(QWidget *parent = nullptr);
    ~showvideo();

    int convert_yuv_to_rgb_pixel(int y, int u, int v);

    int convert_yuv_to_rgb_buffer(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height);

signals:

public slots:
    void paintEvent(QPaintEvent *);

private:
    videodevice *vd;   //videodevice 对象
    QLabel *label;     //用于显示视频图片
    QImage *img;     //图片
    QTimer *timer;     //定时器
    uchar  *pp;        //转换之后的视频数据
    uchar  *p;         //存放获取的原始视频数据
    int    len;        //存放原始视频数据长度

};

#endif // SHOWVIDEO_H
