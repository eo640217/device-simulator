#include "currentcontrol.h"

CurrentControl::CurrentControl(QObject *parent) : QObject(parent)
{
    current = STARTING_CURRENT;
}

int CurrentControl::getCurrent() { return current; }

void CurrentControl::increaseCurrent()
{
    if (current + 50 > 500) {
        current = 500;
    } else {
        current += 50;
    }

    emit currentChanged(current);


}

void CurrentControl::decreaseCurrent()
{
    if (current - 100 < 0) {
        current = 0;
    } else {
        current -= 100;
    }

    emit currentChanged(current);
}

void CurrentControl::resetCurrent() {
    current = STARTING_CURRENT;
}
