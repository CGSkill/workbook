#ifndef RESOURCE_MINITOR_H
#define RESOURCE_MINITOR_H

#include <QObject>

class resource_minitor : public QObject
{
    Q_OBJECT
public:
    explicit resource_minitor(QObject *parent = nullptr);

signals:

public slots:
};

#endif // RESOURCE_MINITOR_H
