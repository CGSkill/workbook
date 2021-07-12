#include "resource_minitor.h"
#include "sys/statfs.h"

resource_minitor::resource_minitor(QObject *parent) : QObject(parent)
{
    connect(&monitor_timer_, &QTimer::timeout, this, &resource_minitor::get_resource_);
    monitor_timer_.start(m_timer_interval_);
}

void resource_minitor::get_resource_()
{
    get_mem_usage_();
    get_net_usage_();
    get_disk_speed_();
    get_cpu_usage_();
    get_disk_space_();
    get_path_space("/");
    qDebug() << "\n";
}

bool resource_minitor::get_mem_usage_() //获取内存
{
    QProcess process;
    process.start("free -m");//使用free完成获取
    process.waitForFinished();
    process.readLine();
    QString str = QString::fromStdString(process.readLine().toStdString());
    str.replace("\n","");
    str.replace(QRegExp("( ){1,}"), " ");//将连续空格替换为单个空格 用于分割
    auto lst = str.split(" ");
    if (lst.size() > 6) {
        qDebug("mem total:%.01fMB free:%.01fMB",lst[1].toDouble()/1024.0,lst[6].toDouble()/1024.0);
        return true;
    }
    process.destroyed();
    return false;
}

bool resource_minitor::get_net_usage_()
{
    QProcess process;
    //face |bytes    packets errs drop fifo frame compressed multicast|bytes    packets errs drop fifo colls carrier compressed
    process.start("cat /proc/net/dev");//读取文件/proc/net/dev 获取网路收发包数量，再除取样时间得到网路苏速度
    process.waitForFinished();
    process.readLine();
    process.readLine();
    while (!process.atEnd()) {
        QString str = process.readLine();
        str.replace("\n", "");
        str.replace(QRegExp("( ){1,}"), " ");
        auto lst = str.split(" ");
        if (lst.size() > 9 && lst[0] == netWorkCart) {
            double recv = 0;
            double send = 0;

            recv = lst[1].toDouble();
            send = lst[9].toDouble();

            qDebug("%s 接收速度：&.01fbyte/s 发送速度：%.01fbyte/s",
                   lst[0].toStdString().c_str(),
                    (recv-m_recv_bytes_)/(m_timer_interval_/1000.0),
                    (send - m_send_bytes_)/(m_timer_interval_/1000.0));
            m_recv_bytes_ = recv;
            m_send_bytes_ = send;
        }
    }
    process.destroyed();
    return true;
}

bool resource_minitor::get_disk_speed_()
{
    QProcess process;
    process.start("iostat -k -d");
    process.waitForFinished();
    process.readLine();
    process.readLine();
    process.readLine();

    QString str = process.readLine();
    str.replace("\n", "");
    str.replace(QRegExp("( ){1,}"), " ");
    auto lst = str.split(" ");
    if (lst.size() >5) {
        qDebug("disk read:%.01fkb/s disk write:%.01fkb/s",
               (lst[4].toDouble() -m_disk_read_)/(m_timer_interval_/1000.0),
                (lst[5].toDouble() - m_disk_write_)/(m_timer_interval_/1000.0));
        m_disk_read_ = lst[4].toDouble();
        m_disk_write_ = lst[5].toDouble();
        return true;
    }
    return false;
}

bool resource_minitor::get_cpu_usage_()
{
    QProcess process;
    process.start("cat /proc/stat");//CPU指标：user，nice, system, idle, iowait, irq, softirq
    process.waitForFinished();
    process.readLine();
    QString str = process.readLine();
    str.replace("\n", "");
    str.replace(QRegExp("( ){1,}"), " ");
    auto lst = str.split(" ");
    if (lst.size() > 3) {
        double use = lst[1].toDouble() + lst[2].toDouble() + lst[3].toDouble();
        double total = 0;
        for (int i = 1; i < lst.size(); ++i) {
            total += lst[i].toDouble();
        }
        if (total - m_cpu_total_ > 0)
        {
            qDebug("cpu rate:%.2lf%%",(use - m_cpu_use_) / (total - m_cpu_total_) * 100.0);
            m_cpu_total_ = total;
            m_cpu_use_ = use;
            return true;
        }
    }
    return false;
}

bool resource_minitor::get_disk_space_()
{
    QProcess process;
    process.start("df -k");
    process.waitForFinished();
    process.readLine();
    while (!process.atEnd()) {
        QString str = process.readLine();
        if (str.startsWith("/dev/sda")) {
            str.replace("\n", "");
            str.replace(QRegExp("( ){1,}"), " ");
            auto lst = str.split(" ");
            if (lst.size() > 5)
                qDebug("挂载点:%s 已用:%.0lfMB 可用:%.0lfMB",
                       lst[5].toStdString().c_str(),
                        lst[2].toDouble()/1024.0,
                        lst[3].toDouble()/1024.0);
        }
    }
    return true;
}

bool resource_minitor::get_path_space(const QString &path)
{
    struct statfs diskInfo;
    statfs(path.toUtf8().data(), &diskInfo);
    qDebug("%s 总大小:%.0lfMB 可用大小:%.0lfMB",
           path.toStdString().c_str(),
           (diskInfo.f_blocks * diskInfo.f_bsize)/1024.0/1024.0,
           (diskInfo.f_bavail * diskInfo.f_bsize)/1024.0/1024.0);
    return true;
}
