#include "battery.h"

Battery::Battery(QObject *parent) : QObject(parent)
{

}

int Battery::getPower() {
    return -1;
}

void setDrain(double d) {
}
