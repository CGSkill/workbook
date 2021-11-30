#ifndef VIDEODEVICE_H
#define VIDEODEVICE_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <linux/videodev2.h>
#include <error.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdint.h>
#include <asm/types.h>
#include <malloc.h>

#define DEVICE_NAME  "/dev/video0"

class videodevice
{
private:
    typedef struct VideoBuffer   //用户空间机构体
    {
        unsigned char *start;    //开始位置
        size_t length;
    }VideoBuffer;

    VideoBuffer *buffers;

    int fd;                     //打开设备文件的描述符

    unsigned int iCount;        //表示申请多少帧

    int  iIndex;                //表示第几帧

public:
    videodevice ();
    ~videodevice();

    int open_device();         //打开视频设备

    int close_device();         //关闭视频设备

    int init_device();          //初始化设备

    int init_mmap();            //初始化内存

    int init_v4l2();            //初始化v4l2

    int start_capturing();       //开始视频采集

    int stopt_capturing();       //停止视频采集

    int get_frame(void **, int *); //获取数据

    int unget_frame();          //帧缓存回收

};

#endif // VIDEODEVICE_H
