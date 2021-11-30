#ifndef GRAPHLIST_H
#define GRAPHLIST_H
/**
 * @Author
 * @Description 图表的数据来源(温度曲线图)
 * @Date 2020-1-4
 */

#include <QObject>
#include <QtMath>
#include <QTimer>
#include <QTime>
#include <QDebug>


class GraphList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int lineLength READ getLineLength NOTIFY lineLengthChanged)
    Q_PROPERTY(int lineSize READ getLineSize NOTIFY lineSizeChanged)
public:
    explicit GraphList(QObject *parent = nullptr);
    ~GraphList();
    Q_INVOKABLE void istimeOut();
    Q_INVOKABLE void clearData();
    Q_INVOKABLE float getDataSource(int number);
    int getLineCount();
    int getLineLength();
    int getLineSize();
    void  setWorkSide(int side);

    float generateRandomNumber();

signals:
    void lineCountChanged();
    void lineLengthChanged();
    void lineSizeChanged();
    void workSideChanged();
private:
    int mLineLength;
    QVector<float> mDataSource;
};

#endif // GRAPHLIST_H
