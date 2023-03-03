#include "showvideo.h"

showvideo::showvideo(QWidget *parent) : QWidget(parent)
{
    vd = new videodevice;

    int iRet = vd->open_device();        //打开摄像头设备
    if (-1 == iRet)
    {
        vd->close_device();              //关闭摄像头
    }

    iRet = vd->init_v4l2();             //初始化v4l2
    if (-1 == iRet)
    {
        vd->close_device();             //关闭摄像头
    }

    iRet = vd->start_capturing();       //开始视频采集
    if (-1 == iRet)
    {
        vd->stopt_capturing();          //停止视频采集
        vd->close_device();             //关闭摄像头
    }

    this->timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));  //update事件会调用paintEvent
    timer->start(30);

    pp = (unsigned char *) malloc(320 *240 *3 * sizeof (char));
    //this->img = new QImage(pp, 320,240, QImage::Format_RGB888);

    label = new QLabel();
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(label);
    this->setLayout(hLayout);
    setWindowTitle(tr("Capture"));

}

showvideo::~showvideo()
{
    vd->stopt_capturing();
    vd->close_device();
}


//yuv 格式转换为 rgb 格式的算法处理函数
int showvideo::convert_yuv_to_rgb_pixel(int y, int u, int v)
{
    unsigned int pixel32 = 0;
    unsigned char *pixel = (unsigned char *)&pixel32;

    int r,g,b;
    r = (int)(y + (1.370705 * (v-128)));
    g = (int)(y - (0.698001 * (v-128)) - (0.337633 * (u-128)));
    b = (int)(y + (1.732446 * (u-128)));
    if (r >255) r = 255;
    if (g >255) g = 255;
    if (b >255) b = 255;

    if (r < 0) r =0;
    if (g < 0) g =0;
    if (b < 0) b =0;

    pixel[0] = r * 220/256;
    pixel[1] = g * 220/256;
    pixel[2] = b * 220/256;

    return  pixel32;

}


int showvideo::convert_yuv_to_rgb_buffer(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height)
{/*
    unsigned int    in, out = 0;
    unsigned int    pixel_16;
    unsigned char   pixel_24[3];
    unsigned int    pixel32;

    int y0,u,y1,v;
    for (in = 0; in < width*height*2; in +=4) {
        pixel_16 = yuv[in +3] << 24 | yuv[in + 2] << 16 | yuv[in+1] << 8 | yuv[in +0];
        y0 = (pixel_16 & 0x000000ff);
        u  = (pixel_16 & 0x0000ff00) >> 8;
        y1 = (pixel_16 & 0x00ff0000) >> 16;
        v  = (pixel_16 & 0xff000000) >> 24;

        pixel32 = convert_yuv_to_rgb_pixed(y0, u, v);
        pixel_24[0] = (pixel32 & 0x000000ff);
        pixel_24[1] = (pixel32 & 0x0000ff00) >> 8;
        pixel_24[2] = (pixel32 & 0x00ff0000) >> 16;

        rgb[out++] = pixel_24[0];
        rgb[out++] = pixel_24[1];
        rgb[out++] = pixel_24[2];

        pixel32 = convert_yuv_to_rgb_pixed(y1, u, v);
        pixel_24[0] = (pixel32 & 0x000000ff);
        pixel_24[1] = (pixel32 & 0x0000ff00) >> 8;
        pixel_24[2] = (pixel32 & 0x00ff0000) >> 16;
        rgb[out++] = pixel_24[0];
        rgb[out++] = pixel_24[1];
        rgb[out++] = pixel_24[2];

    }
    return  0;*/
    uint in, out = 0;
    uint pixel_16;
    uchar pixel_24[3];
    uint pixel32;
    int y0, u, y1, v;
    for(in = 0; in < width * height * 2; in += 4) {
        pixel_16 =
                yuv[in + 3] << 24 |
                               yuv[in + 2] << 16 |
                                              yuv[in + 1] <<  8 |
                                                              yuv[in + 0];//YUV422每个像素2字节，每两个像素共用一个Cr,Cb值，即u和v，RGB24每个像素3个字节
        y0 = (pixel_16 & 0x000000ff);
        u  = (pixel_16 & 0x0000ff00) >>  8;
        y1 = (pixel_16 & 0x00ff0000) >> 16;
        v  = (pixel_16 & 0xff000000) >> 24;
        pixel32 = convert_yuv_to_rgb_pixel(y0, u, v);
        pixel_24[0] = (pixel32 & 0x000000ff);
        pixel_24[1] = (pixel32 & 0x0000ff00) >> 8;
        pixel_24[2] = (pixel32 & 0x00ff0000) >> 16;
        rgb[out++] = pixel_24[0];
        rgb[out++] = pixel_24[1];
        rgb[out++] = pixel_24[2];//rgb的一个像素
        pixel32 = convert_yuv_to_rgb_pixel(y1, u, v);
        pixel_24[0] = (pixel32 & 0x000000ff);
        pixel_24[1] = (pixel32 & 0x0000ff00) >> 8;
        pixel_24[2] = (pixel32 & 0x00ff0000) >> 16;
        rgb[out++] = pixel_24[0];
        rgb[out++] = pixel_24[1];
        rgb[out++] = pixel_24[2];
    }
    return 0;
}

void showvideo::paintEvent(QPaintEvent *)
{
    vd->get_frame((void ** )&p, &len);    //获得视频采集的初始数据
    convert_yuv_to_rgb_buffer(p, pp, 320, 240); //数据转换

    QImage img = QImage(pp, 320,240, QImage::Format_RGB888);

    //this->img->loadFromData((uchar *)pp , 320*240*3*sizeof (char));
    label->setPixmap(QPixmap::fromImage(img, Qt::AutoColor));
    vd->unget_frame();                     //重新放到队列末尾
    qDebug() << "----------------------------------------------------" << pp  << ":"<< p;
}
