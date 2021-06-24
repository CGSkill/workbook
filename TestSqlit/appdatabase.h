#ifndef APPDATABASE_H
#define APPDATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QList>
#include <QMap>
#include <QDebug>
#include <QtGlobal>
#include <QSqlQuery>
#include <QProcess>
#include <QDebug>
#include <iostream>
#include "databasesql.h"

#define APPDATABASEINSTANCE AppDatabase::getInstance()

class AppDatabase
{
public:
    static AppDatabase* getInstance()
    {
        if (appDatabase == nullptr) {
            appDatabase = new AppDatabase ();
        }
        return appDatabase;
    }

    static void quite();

    bool creatTable(const QString sqlStr);
    bool insertData(const QString sqlStr);
    bool updateData(const QString sqlStr);
    bool selectData(const QString sqlStr, QList<QMap<QString, QVariant>> &valuesList);
    bool deleteData(const QString sqlStr);
    bool openDataBase();
    bool initDataBase();


private:
    AppDatabase(); //禁止构造函数
    AppDatabase(const AppDatabase&){} //禁止拷贝构造函数
    AppDatabase & operator =(const AppDatabase&){ return *this;} //禁止赋值拷贝构造函数

private:
    static AppDatabase *appDatabase;

    static QSqlDatabase database;
    static QString dbPath;
    //    static QString dbFile;
    //    static QString dbName;
};

#endif // APPDATABASE_H
