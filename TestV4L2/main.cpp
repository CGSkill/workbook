#include "showvideo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    showvideo sv;
    sv.resize(320,240);
    sv.show();
    return a.exec();
}
