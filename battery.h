#ifndef BATTERY_H
#define BATTERY_H

#include <QObject>
#include "recording.h"
#include "devicestatus.h"
#include <QDebug>

class Battery : public QObject
{
    Q_OBJECT
private:
    double power;
    double drain;

public:
    explicit Battery(QObject *parent = nullptr);
    void setDrain(Recording* c, DeviceStatus d);
    int getPower();
    void drainTick();

public slots:
    void onCharge();
};

#endif // BATTERY_H
