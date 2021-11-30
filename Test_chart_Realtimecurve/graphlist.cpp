#include "graphlist.h"

GraphList::GraphList(QObject *parent) : QObject(parent)
{
    mLineLength = 10;
}

GraphList::~GraphList()
{
    clearData();
}

/**
 * @brief 定时刷新动作
 * @param
 * @return void
 */
void GraphList::istimeOut()
{
    int length = mDataSource.size();
    if(length < mLineLength){
        mDataSource.append(generateRandomNumber());
    }else {
        mDataSource.removeFirst();
        mDataSource.append(generateRandomNumber());
    }
}

void GraphList::clearData()
{
    //qDebug()<<"clearData";
    mDataSource.clear();

}

float GraphList::getDataSource(int number)
{
    if(number < 0 ){
        return 0;
    }
    qDebug() << " GraphList::getDataSource: " << mDataSource[number] << "  "  << number;
    return mDataSource[number];
}

int GraphList::getLineLength()
{
    return mLineLength;
}

int GraphList::getLineSize()
{
    return mDataSource.count();
}

float GraphList::generateRandomNumber()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int tmp = qrand()%10;
    //qDebug() << "generateRandomNumber: " << tmp;
    return tmp;
}
