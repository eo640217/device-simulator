#include "recording.h"
#include <QDebug>

Recording::Recording(QObject *parent) : QObject(parent)
{
    length = 0;
    wave = Waveform::ALPHA;
    freq = Frequency::POINT_FIVE;
    date = QDate::currentDate();
    current = 100;
}


Waveform Recording::getWaveform() {
    return wave;
}

void Recording::setWaveform(Waveform w){
    qDebug() << "RECORDING: set wave";
    wave = w;
}

Frequency Recording::getFreq() {
    return freq;
}

void Recording::setFreq(Frequency f) {
    qDebug() << "RECORDING: set freq";
    freq = f;
}

void Recording::incrementSecond() {
    length++;
    qInfo("treatment time: %d",length);
}

int Recording::getLength() {
    return length;
}

void Recording::setCurrent(int c) {
    current = c;
}

int Recording::getCurrent() {
    return current;
}

QDate* Recording::getDate() {
    return &date;
}

