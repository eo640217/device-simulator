#include "cesdevice.h"

CESDevice::CESDevice(QObject *parent) : QObject(parent)
{
    status = DeviceStatus::OFF;
    //set shutdown time
    shutdownTime = AutoShutdown::TWENTY_M;
    if (shutdownTime == AutoShutdown::TWENTY_M)
        autoS = 20;
    else if (shutdownTime == AutoShutdown::FOURTY_M)
        autoS = 40;
    else
        autoS = 60;

    saveRecording = true;
    powerWarned = false;

    // configure the power and other stuff...

    // connect the slots to their respective events TODO...

    // menu navigation /* UNCOMMENT WHEN UI IS ADDED */
    // connect(ui->upButton, &QPushButton::pressed, this, &CESDevice::navigateUpMenu);
    // connect(ui->downButton, &QPushButton::pressed, this, &CESDevice::navigateDownMenu);

    // current change buttons
    // connect(&ui->leftCurrentButton, &QPushButton::pressed, this, &CESDevice::leftCurrentChange)
    // connect(&ui->rightCurrentButton, &QPushButton::pressed, this, &CESDevice::rightCurrentChange)

    // if idleT goes off then shutdown
    connect(&idleT, &QTimer::timeout, this, &CESDevice::shutdown);

    // every tick call onTick()
    connect(&tickT, &QTimer::timeout, this, &CESDevice::onTick);
}

void CESDevice::shutdown() {
    // make sure we stop idleT

    qInfo("shutting down");

    powerWarned = false;

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

}
//UNCOMMENT WHEN UI IS ADDED
/*
void CESDevice::navigateUpMenu() {
    // CHANGE menuListView to whatever the name on ui is
    int i = ui->menuListView->currentRow() - 1;

    if (i < 0) {
        i = ui->menuListView->count() - 1;
    }

    //ui->menuListView->setCurrentRow(i);
}


void CESDevice::navigateDownMenu() {
    // CHANGE menuListView to whatever the name on ui is
    int i = ui->menuListView->currentRow() + 1;

    if (i > ui->menuListView->count() - 1) {
        i = ui->menuListView->count() - 1;
    }
    //ui->menuListView->setCurrentRow(i);
}
void leftCurrentChange() { cController.incrementCurrent(); }
void rightCurrentChange() { cController.incrementCurrent(); }
*/

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
        // update gui display for timer/current here
        displayTimer();
        displayCurrent();

    }
}

void CESDevice::displayTimer() {
    qDebug() << "Timer: " << autoS - current->getLength();
}

void CESDevice::displayCurrent() {
    qDebug() << "Current: " << cController.getCurrent();
}

void CESDevice::onCurrentChange(int c) {
    current->setCurrent(c);

    // update battery drain
    battery.setDrain(current, status);
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

    // update the battery drain
    battery.setDrain(current, status);
}

void CESDevice::setAutoShutdown(int s) {
    autoS = s;
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
