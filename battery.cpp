#include "battery.h"

Battery::Battery(QObject *parent) : QObject(parent)
{
    drain = 0.01;
    power = 100;

}

int Battery::getPower() {
    return power;
}

void Battery::setDrain(Recording* c, DeviceStatus d) {
    // base drain is always 0.001 per second
    if (d == DeviceStatus::IDLE || d == DeviceStatus::PAUSED || d == DeviceStatus::DISABLED) {
        drain = 0.001;
        return;
    }

    // calculate the new battery drain (0.00004 / uA)
    // freq 0.5 = 0.001; freq 77 = 0.002; freq 100 = 0.003
    drain = c->getCurrent() * 0.000004 + (((int) c->getFreq() + 1) * 0.001);
}


void Battery::drainTick() {
    // if we are in negatives
    if (power - drain <= 0) {
        power = 0;
    } else {
        power -= drain;
    }

    qDebug() << "BATTERY LEVEL: " << power << " drained on level " << drain;
}

void Battery::onCharge() {
    power = 100;
}
