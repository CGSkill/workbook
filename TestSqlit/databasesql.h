#ifndef DATABASESQL_H
#define DATABASESQL_H

#include <QString>
/**
  * 通过宏定义创建SQL语句
  * */

#ifdef ARM

#define DB_PATH "/home/root/client/DB_SHZN_WJJ"

#else

#define DB_PATH "/home/xx/DB_SHZN_WJJ"

#endif

//系统故障
#define SQL_CREAT_ERRORMACHINE  QString("CREATE TABLE errormachine (code varchar(10), content varchar(100), count int, dt varchar(30))")

//GPS故障
#define SQL_CREAT_ERRORGPS  QString("CREATE TABLE errorgps (code varchar(10),content varchar(100), count int, dt varchar(30))")

//发动机故障
#define SQL_CREAT_ERRORENGINE  QString("CREATE TABLE errorEngine (spn int,fmi int,diffid int, count int,dt varchar(30))")

//当前发动机故障
#define SQL_CREAT_CURRENTERRORENGINE  QString("CREATE TABLE currenterrorEngine (id int, fault varchar)")
#define SQL_INITE_CURRENTERRORENGINE  QString("INSERT INTO currenterrorEngine VALUES (0,'')")

//当前系统故障
#define SQL_CREAT_CURRENTERRORSYSTEM  QString("CREATE TABLE currenterrorSystem (id int, fault varchar)")
#define SQL_INITE_CURRENTERRORSYSTEM  QString("INSERT INTO currenterrorSystem VALUES (0,'')")

//当前GPS故障
#define SQL_CREAT_CURRENTERRORGPS  QString("CREATE TABLE currenterrorGps (id int, fault varchar)")
#define SQL_INITE_CURRENTERRORGPS  QString("INSERT INTO currenterrorGps VALUES (0,'')")

//机器信息
#define SQL_CREAT_MACHINEINFOR  QString("CREATE TABLE machineinfor ( id int not null ,developmentcode varchar(50), machinenumber varchar(50), enginemodel varchar(50))")
#define SQL_INITE_MACHINEINFOR  QString("INSERT INTO machineinfor VALUES (0, '869', '0', '康明斯')")

//泵参数设置
#define SQL_CREAT_PUMPPOWERPARAMETERS QString("CREATE TABLE pumppowerparameters ( id int not null , p1 int, p2 int, p3 int, p4 int, p5 int, p6 int, p7 int, p8 int)")
#define SQL_INITE_PUMPPOWERPARAMETERS QString("INSERT INTO pumppowerparameters VALUES (0, 0, 0, 0, 0, 0, 0, 0, 0)")

//一键怠速/自动怠速档位
#define SQL_CREAT_IDLEGEAR QString("CREATE TABLE idleGear ( id int not null , onekey int, autoidle int)")
#define SQL_INITE_IDLEGEAR QString("INSERT INTO idleGear VALUES (0, 1, 1)")

//屏幕亮度
#define SQL_CREAT_SCREENBRIGHTNESS QString("CREATE TABLE screenBrightness ( id int not null , brightness int)")
#define SQL_INITE_SCREENBRIGHTNESS QString("INSERT INTO screenBrightness VALUES (0, 50)")

//保养时间
#define SQL_CREAT_MAINTENANCETIMESET QString("CREATE TABLE maintenancetimeset ( id int not null ,t50 int,t250 int,t500 int,t1000 int, t2000 int)")
#define SQL_INITE_MAINTENANCETIMESET QString("INSERT INTO maintenancetimeset VALUES (0, 3000, 15000, 30000, 60000, 120000)")

//保养倒计时
#define SQL_CREAT_MAINTENANCECOUNTDOWN QString("CREATE TABLE maintenancecountdown ( id int not null , t8 int,t50 int,t250 int,t500 int,t1000 int, t2000 int, isT8 int, isT50 int)")
#define SQL_INITE_MAINTENANCECOUNTDOWN QString("INSERT INTO maintenancecountdown VALUES (0, 480,3000, 15000, 30000, 60000, 120000,1,1)")

//当前发动机时间  engineTime 按分钟记录
#define SQL_CREAT_CURRENTENGINETIME QString("CREATE TABLE currentenginetime ( id int not null , engineTime int)")
#define SQL_INITE_CURRENTENGINETIME QString("INSERT INTO currentenginetime VALUES (0, 0)")

//液压剪
#define SQL_CREAT_HYDRAULICSHEAR QString("CREATE TABLE hydraulicshear ( id int not null ,flow int,pressure int)")
#define SQL_INITE_HYDRAULICSHEAR QString("INSERT INTO hydraulicshear VALUES (0, 50, 50)")

//液压锤
#define SQL_CREAT_HYDRAULICHAMMER QString("CREATE TABLE hydraulichammer ( id int not null ,flow int,pressure int)")
#define SQL_INITE_HYDRAULICHAMMER QString("INSERT INTO hydraulichammer VALUES (0, 50, 50)")

//液压夯
#define SQL_CREAT_HYDRAULICRAMMER QString("CREATE TABLE hydraulicrammer ( id int not null ,flow int,pressure int)")
#define SQL_INITE_HYDRAULICRAMMER QString("INSERT INTO hydraulicrammer VALUES (0, 50, 50)")

//用户密码
#define SQL_CREAT_NEEDKEY QString("CREATE TABLE needkey (id int, userpwd varchar(50), systempwd varchar(50))")
#define SQL_INITE_NEEDKEY QString("INSERT INTO needkey VALUES (0, '000000', '572597')")

//冷却风扇正返转 //0 正  1反
#define SQL_CREAT_COOLINGFAN QString("CREATE TABLE coolingfan (id int, mystate int)")
#define SQL_INITE_COOLINGFAN QString("INSERT INTO coolingfan VALUES (0, 0)")

//发动机冷却风扇正返转 //0 正  1反
#define SQL_CREAT_ENGINECOOLINGFAN QString("CREATE TABLE enginecoolingfan (id int, mystate int)")
#define SQL_INITE_ENGINECOOLINGFAN QString("INSERT INTO enginecoolingfan VALUES (0, 0)")

//语言切换 //0 中文 1 英文
#define SQL_CREAT_LANGUAGESTATE QString("CREATE TABLE languageState (id int, num int)")
#define SQL_INITE_LANGUAGESTATE QString("INSERT INTO languageState VALUES (0, 0)")

//自动怠速状态 0 OFF 1 ON
#define SQL_CREAT_AUTOIDLESTATE QString("CREATE TABLE autoidlestate (id int, state int)")
#define SQL_INITE_AUTOIDLESTATE QString("INSERT INTO autoidlestate VALUES (0, 0)")

//阶段小时计
#define SQL_CREAT_HIRETIMESTATE QString("CREATE TABLE hireTimestate (id int, state int, startTime double, currentDuration  double)")
#define SQL_INITE_HIRETIMESTATE QString("INSERT INTO hireTimestate VALUES (0, 0, 0.0, 0.0)")

//蜂鸣器状态 //0 OFF 1 ON
#define SQL_CREAT_BUZZERSTATE QString("CREATE TABLE buzzerState (id int, state int)")
#define SQL_INITE_BUZZERSTATE QString("INSERT INTO buzzerState VALUES (0, 1)")

//高转速模式  H+模式
#define SQL_CREAT_HIGHSPEEDMODE QString("CREATE TABLE highspeedmode (id int, hmode int)")
#define SQL_INITE_HIGHSPEEDMODE QString("INSERT INTO highspeedmode VALUES (0, 0)")

//附具工具  //b锤 k 剪 r 夯 o 空
#define SQL_CREAT_USETOOL QString("CREATE TABLE useTool (id int, tool varchar)")
#define SQL_INITE_USETOOL QString("INSERT INTO useTool VALUES (0, '0')")

//高原模式 0 非高原 1 高原模式
#define SQL_CREAT_GAOYUANMODEL QString("CREATE TABLE gaoyuanModel (id int, state int)")
#define SQL_INITE_GAOYUANMODEL QString("INSERT INTO gaoyuanModel VALUES (0, 0)")

//合流模式  //0 关闭 1 打开
#define SQL_CREAT_COMBINEDMODEL QString("CREATE TABLE combinedModel (id int, state int)")
#define SQL_INITE_COMBINEDMODEL QString("INSERT INTO combinedModel VALUES (0, 0)")


#endif // DATABASESQL_H
