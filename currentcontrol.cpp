#include "currentcontrol.h"

CurrentControl::CurrentControl(QObject *parent) : QObject(parent)
{
    current = 250;
}

int CurrentControl::getCurrent() { return current; }

void CurrentControl::increaseCurrent()
{
    current += 50;
}

void CurrentControl::decreaseCurrent()
{
    current -= 100;
}
