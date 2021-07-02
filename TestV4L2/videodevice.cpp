#include "videodevice.h"

videodevice::videodevice()
{
    this->fd = -1;
    this->iCount = 4;
    this->iIndex = -1;
    this->buffers = nullptr;
}

videodevice::~videodevice()
{

}

int videodevice::open_device()
{
    this->fd = open(DEVICE_NAME,O_RDWR,0);
    if (-1 == this->fd){
        perror("open error");
        return  -1;
    }

    return 0;
}

int videodevice::close_device()
{
    if (-1 == close(this->fd)) {
        return  -1;
    }

    return  0;
}

int videodevice::init_device()
{
    //查询v4l2设备驱动的功能，例如设备驱动名，总线信息，版本信息等
    struct v4l2_capability cap;   //V4L2 驱动功能
    memset(&cap, 0, sizeof (cap));

    if (-1 == ioctl(this->fd, VIDIOC_QUERYCAP, &cap)) //查询驱动功能
    {
        perror("ioctl VIDIOC_QUERYCAP error !");
        return -1;
    }

    if (!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE)) return -1;

    if (!(cap.capabilities & V4L2_CAP_STREAMING)) return  -1;

    //可以打印v4l2设备的相关信息
    printf("Capability inframtions: \n");
    printf("driver: %s \n", cap.driver);
    printf("card: %s \n", cap.card);
    printf("bus_info: %s \n", cap.bus_info);
    printf("version: %08X \n", cap.version);
    printf("capability: %08X \n",cap.capabilities);

    //设置视频捕获格式，设置视频图像数据长，宽，图像格式（如 JPEG， YUYV等）
    struct v4l2_format fmt;             //设置获取视频的格式
    memset(&fmt, 0 , sizeof (fmt));     //将结构体清空

    //视频数据流类型，永远都是V4L2_BUF_TYPE_VIDEO_CAPTURE
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;      //视频源的格式为JPEG或YUYV或RGB
    fmt.fmt.pix.width = 320;                          //设置视频宽度
    fmt.fmt.pix.height = 240;                         //设置视频高度
    fmt.fmt.pix.field = V4L2_FIELD_INTERLACED;        //设置区域
    if ( -1 == ioctl(this->fd, VIDIOC_S_FMT, &fmt))                                             //设置视频捕捉格式
    {
        perror("ioctl VIDIOC_S_FMT ERROR");
        return -1;
    }

    return 0;
}

int videodevice::init_mmap()
{
    //申请内核帧缓存
    struct v4l2_requestbuffers req;                 //向内核申请帧缓冲的请求
    memset(&req, 0, sizeof (req));
    req.count = this->iCount;                       //缓存数量，既可保存的图片数量

    //数据类型，永远都是 V4L2_BUF_TYPE_VIDEO_CAPTURE
    req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    /*存储类型：V4L2_MEMORY_MMAP 或 V4L2_MEMORY_USERPTR
     *这里采用内存映射的方式
    */
    req.memory = V4L2_MEMORY_MMAP;
    //VIDIOC_REQBUFS 表示分配内存，调用ioctl使用配置生效
    if ( -1 == ioctl(this->fd, VIDIOC_REQBUFS, &req))
    {
        perror("ioctl VIDIOC_REQBUFS error");
        exit(-1);
    }
    //到这里，我们已经有了内核帧缓存

    if (req.count < 2) //起检测的作用，保证帧缓存数量大于1（实际测试过程中1个好像不行）
    {
        return  -1;
    }

    /*在用户空间申请count个 VideoBuffer 数据类型的空间，每一个都是由起始地址和空间长度组成，其中start保存等下内存之后返回的
     * 内存首地址
    */
    this->buffers = (VideoBuffer *)calloc(req.count, sizeof (VideoBuffer));

    unsigned int numBufs = 0;
    for (numBufs = 0; numBufs < req.count; numBufs++) //映射所有的缓存
    {
        struct v4l2_buffer buf;    //驱动中的一帧，保存内核中缓冲帧的相关信息结构体
        memset(&buf, 0 , sizeof (buf));
        //数据流类型，永远都是V4L2_BUG_TYPE_VIDEO_CAPTURE
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

        //存储类型：V4L2_MEMORY_MMAP（内存映射）或 V4L2_MEMORY_USERPTR (用户指针)
        buf.memory = V4L2_MEMORY_MMAP;
        buf.index = numBufs;    //帧号
        //获得相应帧号的缓冲帧信息，并保存在v4l2_buf结构体变量buf中
        if (-1 == ioctl(fd, VIDIOC_QUERYBUF, &buf))
        {
            perror("ioctl VIDIOC_QUERYBUF error");
            return -1;
        }

        buffers[numBufs].length = buf.length;   //用户空间的长度
        //使用mmap函数将申请的缓存帧地址映射到用户空间
        buffers[numBufs].start = (unsigned char *)mmap(nullptr,buf.length,PROT_READ | PROT_WRITE,
                                                       MAP_SHARED,fd,buf.m.offset);
        if (buffers[numBufs].start == MAP_FAILED) {
            perror("mmap error \n");
            return -1;
        }

    }
    return 0;

}

int videodevice::init_v4l2()            //初始化 v4l2 设备
{
    if (-1 == init_device()) return -1;  //初始化设备
    if (-1 == init_mmap())   return -1;  //初始化内存

    return 0;
}

int videodevice::start_capturing()      //开始视频采集
{
    unsigned int i;
    for ( i = 0; i< iCount; ++i)
    {
        struct v4l2_buffer buf;
        memset(&buf, 0, sizeof (buf));
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        buf.index = i;

        //将申请到的帧缓冲入队列，以便存储采集到的数据
        if (-1 == ioctl(fd,VIDIOC_QBUF,&buf))
        {
            perror("ioctl VIDIOC_QBUF error");
            return -1;
        }
    }

    enum v4l2_buf_type type;          //开始视频采集
    //数据流类型，永远都是 V4L2_BUF_TYPE_VIDEO_CAPTURE
    type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (ioctl(fd, VIDIOC_STREAMON,&type) < 0)  //采集视频
    {
        perror("ioctl VIDIOC_STREAMON error");
        return  -1;
    }
    return 0;
}

int videodevice::stopt_capturing()   //停止视频采集
{
    enum v4l2_buf_type type;
    //数据流类型，永远都是 V4L2_BUF_TYPE_VIDEO_CAPTURE
    type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (ioctl(fd, VIDIOC_STREAMOFF, &type) < 0)
    {
        perror("ioctl VIDIOC_STREAMOFF error");
        return  -1;
    }
    return  0;
}

int videodevice::get_frame(void **frame_buf, int * len)
{
    struct v4l2_buffer buf;
    memset(&buf, 0, sizeof (buf));
    //数据流类型，永远都是 V4L2_BUF_TYPE_VIDEO_CAPTURE
    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    //存储类型：V4L2_MEMORY_MMAP（内存映射）或 V4L2_MEMORY_USERPTR (用户指针)
    buf.memory = V4L2_MEMORY_MMAP;
    if (ioctl(fd,VIDIOC_DQBUF,&buf) < 0)  //从缓存队列取出一个已经保存有一个帧视频数据的缓冲区
    {
        perror("ioctl VIDIOC_DQBUF failed");
        return -1;
    }
    *frame_buf = buffers[buf.index].start;
    *len = buffers[buf.index].length;
    iIndex = buf.index;

    return 0;
}

int videodevice::unget_frame()
{
    if (iIndex != -1) {
        struct v4l2_buffer buf;
        memset(&buf, 0, sizeof (buf));
        //数据流类型，永远都是 V4L2_BUF_TYPE_VIDEO_CAPTURE
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        //存储类型：V4L2_MEMORY_MMAP（内存映射）或 V4L2_MEMORY_USERPTR (用户指针)
        buf.memory = V4L2_MEMORY_MMAP;
        buf.index = iIndex;
        if (ioctl(fd, VIDIOC_QBUF, &buf) < 0)
        {
            return -1;
        }
        return 0;
    }
    return  -1;
}
