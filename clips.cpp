#include "clips.h"

Clips::Clips(QObject *parent) : QObject(parent)
{
    connected = false;
}

bool Clips::getConnected(){
    return connected;
}
void Clips::setConnected(bool c){
    connected = c;

    qDebug() << "Clips Connected? " << connected;
}
