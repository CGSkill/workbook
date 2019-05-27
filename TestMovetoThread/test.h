#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QVariant>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    QVariant getData() const;
    void setData(const QVariant &value);

private slots:
    void fortest();
signals:

public slots:

private:
    QVariant data;
};

#endif // TEST_H
