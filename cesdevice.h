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
    // change this to change the fraction of time elapsed (1 = realtime, 1s in sim = 1s), (0.5 = 2x speed, 1s in sim = 0.5s), etc
    static double timeFactor;
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

    void charge();
    void displayTimer();
    void displayCurrent();


public:
    explicit CESDevice(QObject *parent = nullptr);
    CurrentControl* getCController();
    DeviceStatus getStatus();
    void shutdown();
    QList<Recording*>* getRecordings();
    Recording* getCurrentRecording();

public slots:
   //void navigateDownMenu();
   //void navigateUpMenu();
   //void leftCurrentChange();
   //void rightCurrentChange();
    void powerUpdate(int p);
    void onTick();
    void onCurrentChange(int c);
    void onClipChange(bool b);
    void setAutoShutdown(AutoShutdown c);
    void powerOn();
    void setSaveRecording(bool b);


signals:
    void powerStatus(int p);
    void currentChanged(int c);
    void shuttingDown();
};

#endif // CESDEVICE_H
