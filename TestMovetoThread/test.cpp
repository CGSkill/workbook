#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{

}

void Test::fortest()
{

    qDebug()<< "-------------" <<QThread::currentThreadId() << ":" <<data.toString() ;
}

QVariant Test::getData() const
{
    return data;
}

void Test::setData(const QVariant &value)
{
    data = value;
}
