#include <QDir>
#include "appdatabase.h"

AppDatabase *AppDatabase::appDatabase = nullptr;

QSqlDatabase AppDatabase::database;
QString AppDatabase::dbPath = DB_PATH;



void AppDatabase::quite()
{
    if (database.isOpen()){
        database.close();
        qInfo("Close database success.");
    }
    qInfo("[ok] AppDatabase quite.");
}

bool AppDatabase::creatTable(const QString sqlStr)
{
    QSqlQuery sql_query(database);
    qInfo("[SQL] %s", qPrintable(sqlStr));
    if (!sql_query.exec(sqlStr)) {
        qWarning("[SQL] %s", qPrintable(sql_query.lastError().text()));
        return false;
    }
    return true;
}

bool AppDatabase::insertData(const QString sqlStr)
{
    QSqlQuery sql_query(database);
    qInfo("[SQL] %s", qPrintable(sqlStr));
    if (!sql_query.exec(sqlStr)) {
        qWarning("[SQL] %s", qPrintable(sql_query.lastError().text()));
        return false;
    }
    QProcess::execute("sync");
    return true;
}

bool AppDatabase::updateData(const QString sqlStr)
{
    QSqlQuery sql_query(database);
    qInfo("[SQL] %s", qPrintable(sqlStr));
    if (!sql_query.exec(sqlStr))
    {
        qWarning("[SQL] %s", qPrintable(sql_query.lastError().text()));
        return  false;
    }
    QProcess::execute("sync");
    return  true;
}

bool AppDatabase::selectData(const QString sqlStr, QList<QMap<QString, QVariant> > &valuesList)
{

}

bool AppDatabase::deleteData(const QString sqlStr)
{
    QSqlQuery sql_query(database);
    qInfo("[SQL] %s", qPrintable(sqlStr));
    if (!sql_query.exec(sqlStr))
    {
        qWarning("[SQL] %s", qPrintable(sql_query.lastError().text()));
        return  false;
    }
    QProcess::execute("sync");
    return  true;
}

bool AppDatabase::openDataBase()
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        database = QSqlDatabase::database("qt_sql_default_connection");
    else
        database = QSqlDatabase::addDatabase("QSQLITE","MAIN");

    database.setDatabaseName(DB_PATH);//数据库文件名，
    if (!database.open()) {//打开数据库，如果不存在则新建立，如果建立失败则返回false
        qWarning() << qPrintable(QString("Connect database error, %1").arg(database.lastError().text()));
        return false;
    } else {
        qInfo() << qPrintable(QString("Connect database succeed."));
        return true;
    }
}

bool AppDatabase::initDataBase()
{
    if (database.open()) {
        QSqlQuery sql_query(database);

        if (database.tables().indexOf("errormachine") == -1) {
            //系统故障
            if (creatTable(SQL_CREAT_ERRORMACHINE) == false)
                return false;
        }

        if (database.tables().indexOf("errorgps") == -1) {
            //GPS故障
            if (creatTable(SQL_CREAT_ERRORGPS) == false)
                return false;
        }

        if (database.tables().indexOf("errorEngine")) {
            //发动机故障
            if (creatTable(SQL_CREAT_ERRORENGINE) == false)
                return false;
        }

        if (database.tables().indexOf("currenterrorEngine")) {
            //当前发动机故障
            if (creatTable(SQL_CREAT_CURRENTERRORENGINE) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_CURRENTERRORENGINE))
                    return false;
            }
        }

        if (database.tables().indexOf("currenterrorSystem")) {
            //当前系统故障
            if (creatTable(SQL_CREAT_CURRENTERRORSYSTEM) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_CURRENTERRORSYSTEM))
                    return  false;
            }
        }

        if (database.tables().indexOf("currenterrorGps")) {
            //当前GPS故障
            if (creatTable(SQL_CREAT_CURRENTERRORGPS) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_CURRENTERRORGPS))
                    return  false;
            }
        }

        if (database.tables().indexOf("machineinfor")) {
            //机器信息
            if (creatTable(SQL_CREAT_MACHINEINFOR) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_CURRENTERRORGPS))
                    return  false;
            }
        }

        if (database.tables().indexOf("pumppowerparameters")) {
            //泵参数设置
            if (creatTable(SQL_CREAT_PUMPPOWERPARAMETERS) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_PUMPPOWERPARAMETERS))
                    return  false;
            }
        }

        if (database.tables().indexOf("idleGear")) {
            //一键怠速/自动怠速档位
            if (creatTable(SQL_CREAT_IDLEGEAR) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_IDLEGEAR))
                    return  false;
            }
        }

        if (database.tables().indexOf("screenBrightness")) {
            //屏幕亮度
            if (creatTable(SQL_CREAT_SCREENBRIGHTNESS) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_SCREENBRIGHTNESS))
                    return  false;
            }
        }

        if (database.tables().indexOf("maintenancetimeset")) {
            //保养时间
            if (creatTable(SQL_CREAT_MAINTENANCETIMESET) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_MAINTENANCETIMESET))
                    return  false;
            }
        }

        if (database.tables().indexOf("maintenancecountdown")) {
            //保养倒计时
            if (creatTable(SQL_CREAT_MAINTENANCECOUNTDOWN) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_MAINTENANCECOUNTDOWN))
                    return  false;
            }
        }

        if (database.tables().indexOf("maintenancecountdown")) {
            //保养倒计时
            if (creatTable(SQL_CREAT_MAINTENANCECOUNTDOWN) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_MAINTENANCECOUNTDOWN))
                    return  false;
            }
        }


        if (database.tables().indexOf("currentenginetime")) {
            //当前发动机时间  engineTime 按分钟记录
            if (creatTable(SQL_CREAT_CURRENTENGINETIME) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_CURRENTENGINETIME))
                    return  false;
            }
        }

        if (database.tables().indexOf("hydraulicshear")) {
            //液压剪
            if (creatTable(SQL_CREAT_HYDRAULICSHEAR) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_HYDRAULICSHEAR))
                    return  false;
            }
        }


        if (database.tables().indexOf("hydraulichammer")) {
            //液压锤
            if (creatTable(SQL_CREAT_HYDRAULICHAMMER) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_HYDRAULICHAMMER))
                    return  false;
            }
        }

        if (database.tables().indexOf("hydraulicrammer")) {
            //液压夯
            if (creatTable(SQL_CREAT_HYDRAULICRAMMER) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_HYDRAULICRAMMER))
                    return  false;
            }
        }


        if (database.tables().indexOf("needkey")) {
            //用户密码
            if (creatTable(SQL_CREAT_NEEDKEY) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_NEEDKEY ))
                    return  false;
            }
        }

        if (database.tables().indexOf("coolingfan")) {
            //冷却风扇正返转 //0 正  1反
            if (creatTable(SQL_CREAT_COOLINGFAN) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_COOLINGFAN))
                    return  false;
            }
        }

        if (database.tables().indexOf("enginecoolingfan")) {
            //发动机冷却风扇正返转 //0 正  1反
            if (creatTable(SQL_CREAT_ENGINECOOLINGFAN) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_ENGINECOOLINGFAN))
                    return  false;
            }
        }

        if (database.tables().indexOf("languageState")) {
            //语言切换 //0 中文 1 英文
            if (creatTable(SQL_CREAT_LANGUAGESTATE) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_LANGUAGESTATE))
                    return  false;
            }
        }

        if (database.tables().indexOf("languageState")) {
            //语言切换 //0 中文 1 英文
            if (creatTable(SQL_CREAT_LANGUAGESTATE) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_LANGUAGESTATE))
                    return  false;
            }
        }

        if (database.tables().indexOf("autoidlestate")) {
            //自动怠速状态 0 OFF 1 ON
            if (creatTable(SQL_CREAT_AUTOIDLESTATE) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_AUTOIDLESTATE))
                    return  false;
            }
        }

        if (database.tables().indexOf("hireTimestate")) {
            //阶段小时计
            if (creatTable(SQL_CREAT_HIRETIMESTATE) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_HIRETIMESTATE))
                    return  false;
            }
        }


        if (database.tables().indexOf("buzzerState")) {
            //蜂鸣器状态 //0 OFF 1 ON
            if (creatTable(SQL_CREAT_BUZZERSTATE) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_BUZZERSTATE))
                    return  false;
            }
        }

        if (database.tables().indexOf("highspeedmode")) {
            //高转速模式  H+模式
            if (creatTable(SQL_CREAT_HIGHSPEEDMODE) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_HIGHSPEEDMODE))
                    return  false;
            }
        }

        if (database.tables().indexOf("useTool")) {
            //具工具  //b锤 k 剪 r 夯 o 空
            if (creatTable(SQL_CREAT_USETOOL) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_USETOOL))
                    return  false;
            }
        }

        if (database.tables().indexOf("gaoyuanModel")) {
            //高原模式 0 非高原 1 高原模式
            if (creatTable(SQL_CREAT_GAOYUANMODEL) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_GAOYUANMODEL))
                    return  false;
            }
        }

        if (database.tables().indexOf("combinedModel")) {
            //合流模式  //0 关闭 1 打开
            if (creatTable(SQL_CREAT_COMBINEDMODEL) == false)
                return false;
            else {
                if (!insertData(SQL_INITE_COMBINEDMODEL))
                    return  false;
            }
        }
    }
    QProcess::execute("sync");
    return true;
}

AppDatabase::AppDatabase()
{
    qInfo("[SQL] %s", qPrintable("wo le ge qu"));
    if (openDataBase()) {
        initDataBase();
    }
}
