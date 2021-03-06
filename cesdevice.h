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

// idle timeout in 30 minutes (1,800,000ms)
#define IDLE_TIMEOUT 1800000

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

    bool powerWarned;

    bool saveRecording;

    Battery battery;
    Clips clips;
    CurrentControl cController;

    QTimer idleT, tickT;

    void treatmentTick();
public:
    // change this to change the fraction of time elapsed (1 = realtime, 1s in sim = 1s), (0.5 = 2x speed, 1s in sim = 0.5s), etc
    static double timeFactor;
    explicit CESDevice(QObject *parent = nullptr);
    void beginTreatment();
    void shutdown();
    void getAutoS();
    void powerOn();

    // getters and setters
    QList<Recording*>* getRecordings();
    Recording* getCurrentRecording();
    void setTimeFactor(int f);
    Battery* getBattery();
    Clips* getClips();
    CurrentControl* getCController();
    DeviceStatus getStatus();
    void setAutoShutdown(AutoShutdown c);


public slots:
    void powerUpdate(int p);
    void onTick();
    void onCurrentChange(int c);
    void onClipChange(bool b);
    void setSaveRecording(bool b);
    void overload();

signals:
    void changeShutdownTimer(int s, int t);
    void powerStatus(int p);
    void currentChanged(int c);
    void shuttingDown();
    void clipChanged(bool b);
};

#endif // CESDEVICE_H
