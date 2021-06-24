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
    typeof  struct VideoBuffer{  //

    }


public:
    videodevice();
};

#endif // VIDEODEVICE_H
