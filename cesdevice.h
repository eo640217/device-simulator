#ifndef CESDEVICE_H
#define CESDEVICE_H

#include "autoshutdown.h"
#include "devicestatus.h"
#include "recording.h"
#include "battery.h"
#include "currentcontrol.h"
#include "clips.h"
#include <QDebug>
#include <QTimer>

// timeout in 30,000ms or 30 seconds if idle (rather than 30 minutes)
#define IDLE_TIMEOUT 30000

// each tick is 1,000ms or 1s
#define TICK 1000

class CESDevice : public QObject
{
    Q_OBJECT

private:
    AutoShutdown shutdownTime;
    DeviceStatus status;

    int autoS;

    Recording* current;
    QList<Recording*> recordings;

    bool powerWarned;

    bool saveRecording;

    Battery battery;
    Clips clips;
    CurrentControl cController;

    QTimer idleT, tickT;

    void treatmentTick();
    void overload();
    void shutdown();
    void charge();
    void displayTimer();
    void displayCurrent();

public:
    explicit CESDevice(QObject *parent = nullptr);

public slots:
   //void navigateDownMenu();
   //void navigateUpMenu();
   //void leftCurrentChange();
   //void rightCurrentChange();
    void powerUpdate(int p);
    void onTick();
    void onCurrentChange(int c);
    void onClipChange(bool b);
    void setAutoShutdown(int c);
    void powerOn();

signals:
    void powerStatus(int p);
};

#endif // CESDEVICE_H
