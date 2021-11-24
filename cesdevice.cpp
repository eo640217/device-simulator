#include "cesdevice.h"

CESDevice::CESDevice(QObject *parent) : QObject(parent)
{
    status = DeviceStatus::OFF;
    autoS = 5;

    saveRecording = true;

    // configure the power and other stuff...

    // connect the slots to their respective events TODO...


    // if idleT goes off then shutdown
    connect(&idleT, &QTimer::timeout, this, &CESDevice::shutdown);

    // every tick call onTick()
    connect(&tickT, &QTimer::timeout, this, &CESDevice::onTick);
}

void CESDevice::shutdown() {
    // make sure we stop idleT

    qInfo("shutting down");

    idleT.stop();

    tickT.stop();

    // save recording (if we were in a treatment)
    if (saveRecording && (status == DeviceStatus::RUNNING || status == DeviceStatus::PAUSED)) {
        recordings.append(current);
        qDebug() << "Saving recording with length " << current->getLength() << " date: " << current->getDate()->toString();
    } else {
        // garbage we didnt do any recording
        free(current);
    }

    status = DeviceStatus::OFF;

    // anything else to do? (power probably)


}

void CESDevice::powerOn() {
    qInfo("test power on");

    // make sure we have power to turn on? TODO

    // just turned it on
    status = DeviceStatus::IDLE;

    // start idle timer
    idleT.start(IDLE_TIMEOUT);
    tickT.start(TICK);

    // recording also stores the state of the CURRENT treatment
    current = new Recording;

    // start power drain?
}

void CESDevice::treatmentTick() {
    // check clip connection TODO (if clips not connected should be in paused state)

    if (status == DeviceStatus::RUNNING) {
        current->incrementSecond();

        if (current->getLength() == autoS) {
            // treatment is done
            shutdown();
        }
    }
}


void CESDevice::onTick() {
    // do some stuff every tick
    qInfo("tick hit");

    // POWER DRAIN should happen probs

    if (status == DeviceStatus::IDLE) {
        // do nothing
        return;
    }

    if (status == DeviceStatus::RUNNING) {
        treatmentTick();
    }
}

void CESDevice::onCurrentChange(int c) {
    current->setCurrent(c);
}

void CESDevice::onClipChange(bool connected) {
    if (connected && status != DeviceStatus::DISABLED && status != DeviceStatus::OFF) {
        qInfo("start treatment for %d", autoS);
        idleT.stop();
        status = DeviceStatus::RUNNING;
    } else if (!connected && status == DeviceStatus::RUNNING) {
        idleT.start(IDLE_TIMEOUT);
        status = DeviceStatus::PAUSED;
    }
}

void CESDevice::setAutoShutdown(int s) {
    autoS = s;
}
