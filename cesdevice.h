#ifndef CESDEVICE_H
#define CESDEVICE_H

#include "devicestatus.h"
#include "recording.h"
#include "battery.h"
#include "currentcontrol.h"
#include "clips.h"
#include <QDebug>

// timeout in 30,000ms or 30 seconds if idle (rather than 30 minutes)
#define IDLE_TIMEOUT 30000

// each tick is 1,000ms or 1s
#define TICK 1000

class CESDevice : public QObject
{
    Q_OBJECT

private:
    DeviceStatus status;

    int autoS;

    Recording* current;
    QList<Recording*> recordings;

    bool saveRecording;

    Battery battery;
    Clips clips;
    CurrentControl cController;

    QTimer idleT, tickT;

    void treatmentTick();
    void overload();
    void shutdown();
    void charge();

public:
    explicit CESDevice(QObject *parent = nullptr);

public slots:
    void onTick();
    void onCurrentChange(int c);
    void onClipChange(bool b);
    void setAutoShutdown(int c);
    void powerOn();

signals:

};

#endif // CESDEVICE_H
