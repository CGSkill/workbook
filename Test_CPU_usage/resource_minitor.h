#ifndef RESOURCE_MINITOR_H
#define RESOURCE_MINITOR_H

#include <QObject>
#include <QTimer>
#include <QProcess>
#include <QtDebug>
#include <QtGlobal>

class resource_minitor : public QObject
{
    Q_OBJECT
public:
    explicit resource_minitor(QObject *parent = nullptr);

signals:

public slots:
    void get_resource_();

private:
    bool get_mem_usage_();
    bool get_net_usage_();
    bool get_disk_speed_();
    bool get_cpu_usage_();
    bool get_disk_space_();
    bool get_path_space(const QString & path);
private:
    const   int m_timer_interval_ = 1000;
    QTimer  monitor_timer_;
    double  m_send_bytes_ = 0;
    double  m_recv_bytes_ = 0;
    double  m_disk_read_ = 0;
    double  m_disk_write_ = 0;
    double  m_cpu_total_ = 0;
    double  m_cpu_use_ = 0;

    QString  netWorkCart = "ens33";
};

#endif // RESOURCE_MINITOR_H
