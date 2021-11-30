#include <qglobal.h>
#include <QQmlEngine>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QCoreApplication>
#include <QQmlPropertyMap>
#include <QQuickView>
#include <QQmlContext>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QFont>
#include <QDebug>
#include <QTextCodec>
#include <QCoreApplication>


#include "graphlist.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    qmlRegisterType<GraphList>("com.mycompany.qmlcomponents", 1, 0, "GraphList");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
