#include "currentcontrol.h"

CurrentControl::CurrentControl(QObject *parent) : QObject(parent)
{
    current = 250;
}

int CurrentControl::getCurrent() { return current; }

void CurrentControl::increaseCurrent()
{
    if (current + 50 > 500) {
        current = 500;
        return;
    }

    current += 50;
}

void CurrentControl::decreaseCurrent()
{
    if (current - 100 < 0) {
        current = 0;
        return;
    }
    current -= 100;
}
