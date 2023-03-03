#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDomDocument doc;
    QFile file("/home/cg/tr_en.ts");
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "cant open!";
        exit(0);
    }
    QString errorMsg;
    //将文件内容读到doc中
    if(!doc.setContent(&file,&errorMsg))
    {
        qDebug() << errorMsg;
        file.close();
        exit(0);
    }

    file.close();
    //获得doc的第一个节点，即XML说明
    QDomNode firstNode = doc.firstChild();

    //<?xml version="1.0" encoding="utf-8"?>
    //    qDebug() << firstNode.nodeName();
    //    qDebug() << firstNode.nodeType();
    //    qDebug() << firstNode.nodeValue();
    //    "xml"
    //    7
    //    "version='1.0' encoding='utf-8'"



    QDomNodeList list =  doc.childNodes();
    for (int i = 0 ; i < list.count(); i++) {
        qDebug() << list.at(i).nodeName();
        //        <?xml version="1.0" encoding="utf-8"?>
        //        <!DOCTYPE TS>
        //        "xml"
        //        "TS"
    }


    QDomElement context;
    while (!firstNode.isNull()) {
        if (firstNode.isElement())
        {
            context = firstNode.firstChildElement("context"); //context
            for (;!context.isNull(); context = context.nextSiblingElement("context"))
            {

                QDomElement message = context.firstChildElement("message"); //message
                for (;!message.isNull(); message = message.nextSiblingElement("message")) {

                    QDomElement source = message.firstChildElement("source");
                    QDomElement translation = message.firstChildElement("translation");

                    qDebug() <<  source.text() << ":" << translation.text();
                }

            }
        }
        firstNode = firstNode.nextSibling();
    }



}





MainWindow::~MainWindow()
{
    delete ui;
}

