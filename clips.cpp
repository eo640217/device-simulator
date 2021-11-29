#include "clips.h"

Clips::Clips(QObject *parent) : QObject(parent)
{
    connected = false;
}

bool Clips::isConnected(){
    return connected;
}
void Clips::connect(){
    connected = true;
}
void Clips::disconnect(){
    //set the connection status to false
    connected = false;
    //if it has been disconnected for 5 seconds return
    if (disconnectionTimer > 5){
        connected = false;
    }
    //else reconnect
    else{
        connect();
    }

    qDebug() << "Clips Connected? " << connected;
    return;

}



