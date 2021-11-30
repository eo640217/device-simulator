#include "cesdevice.h"

double CESDevice::timeFactor = 0.5;

CESDevice::CESDevice(QObject *parent) : QObject(parent)
{
    status = DeviceStatus::OFF;
    //set shutdown time
    setAutoShutdown(AutoShutdown::TWENTY_M);

//    recordings.append(new Recording);
//    recordings.append(new Recording);
//    recordings.append(new Recording);


    saveRecording = true;
    powerWarned = false;

    // configure the power and other stuff...

    // if idleT goes off then shutdown
    connect(&idleT, &QTimer::timeout, this, &CESDevice::shutdown);

    // every tick call onTick()
    connect(&tickT, &QTimer::timeout, this, &CESDevice::onTick);
}

void CESDevice::beginTreatment()
{
    qInfo("start treatment for %d", autoS);
    idleT.stop();
    status = DeviceStatus::RUNNING;
}

void CESDevice::shutdown() {
    // make sure we stop idleT

    qInfo("shutting down");

    emit shuttingDown();

    powerWarned = false;

    idleT.stop();

    tickT.stop();

    if (status == DeviceStatus::DISABLED) {
        qDebug() << "device is disabled!";
        return;
    }

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

    if (status == DeviceStatus::DISABLED) {
        qDebug() << "device is disabled cannot power on!";
        return;
    }

    // just turned it on
    status = DeviceStatus::IDLE;

    // start idle timer
    idleT.start(IDLE_TIMEOUT * timeFactor);
    tickT.start(TICK * timeFactor);

    // recording also stores the state of the CURRENT treatment
    current = new Recording;

}

void CESDevice::treatmentTick() {
    // check clip connection TODO (if clips not connected should be in paused state)
    if (!clips.getConnected()) {
        status = DeviceStatus::PAUSED;
    }

    if (status == DeviceStatus::RUNNING) {
        current->incrementSecond();
        if (current->getLength() == autoS / 5 / 100) {
            // treatment is done
            shutdown();
        }
    }
}

void CESDevice::getAutoS()
{
    emit changeShutdownTimer(autoS, current->getLength());
}
void CESDevice::onTick() {
    // do some stuff every tick
    qInfo("tick hit");
    // power drain
    battery.drainTick();

    int power = battery.getPower();

    powerUpdate(power);

    if (status == DeviceStatus::IDLE) {
        // do nothing
        return;
    }

    if (status == DeviceStatus::RUNNING) {
        treatmentTick();
        getAutoS();
    }

}

void CESDevice::onCurrentChange(int c) {
    current->setCurrent(c);

    // update battery drain
    battery.setDrain(current, status);
}

void CESDevice::onClipChange(bool connected) {
    clips.setConnected(connected);
    if (!connected && status == DeviceStatus::RUNNING) {
        // 5 seconds to reconnect
        idleT.start(TICK * 5 * timeFactor);
        status = DeviceStatus::PAUSED;
    } else if (connected && status == DeviceStatus::PAUSED) {
        idleT.stop();
        status = DeviceStatus::RUNNING;
    }
    emit clipChanged(connected);

    // update the battery drain
    battery.setDrain(current, status);
}

void CESDevice::setAutoShutdown(AutoShutdown s) {
    if (s == AutoShutdown::TWENTY_M)
        autoS = 20 * 60 * TICK * timeFactor;
    else if (s == AutoShutdown::FOURTY_M)
        autoS = 40 * 60 * TICK * timeFactor;
    else
        autoS = 60 * 60 * TICK * timeFactor;
}

void CESDevice::powerUpdate(int p) {
    // for the GUI to hook in
    emit powerStatus(p);

    if (!powerWarned && p <= 5 && p > 2) {
        // issue a warning
        qDebug() << "DEVICE: 5% power warning";
    } else if (p <= 2) {
        qDebug() << "DEVICE: power out shutting down";
        // issue another warning?
        shutdown();
    }

    powerWarned = true;
}

CurrentControl* CESDevice::getCController() {
    return &cController;
}

QList<Recording*>* CESDevice::getRecordings() {
    return &recordings;
}

DeviceStatus CESDevice::getStatus() {
    return status;
}

Recording* CESDevice::getCurrentRecording() {
    return current;
}

void CESDevice::setSaveRecording(bool b) {
    saveRecording = b;
}

void CESDevice::updateTimeFactor(int c) {
    int remaining;
    if (idleT.isActive()) {
        remaining = idleT.remainingTime();
        idleT.stop();
        idleT.start(remaining * (1.0/timeFactor) * (1.0/c));
    }

    if (tickT.isActive()) {
        tickT.stop();
        tickT.start(TICK * (1.0/c));
    }

    CESDevice::timeFactor = 1.0/c;

    qDebug() << "time factor is now " << CESDevice::timeFactor;
}

Battery* CESDevice::getBattery() {
    return &battery;
}

void CESDevice::overload() {
    status = DeviceStatus::DISABLED;

    shutdown();
}

Clips* CESDevice::getClips() {
    return &clips;
}
