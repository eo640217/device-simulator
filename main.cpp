#include "mainwindow.h"
#include "cesdevice.h"

#include <QApplication>

int main(int argc, char *argv[])
{


    // GUI stuff
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    CESDevice device;

//    device.powerOn();
//    device.onClipChange(true);

    return a.exec();
}
