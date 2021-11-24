#include "recording.h"

Recording::Recording(QObject *parent) : QObject(parent)
{
    length = 0;
    wave = Waveform::WAVE_1;
    freq = Frequency::POINT_FIVE;
    date = QDate::currentDate();
}


Waveform Recording::getWaveform() {
    return wave;
}

void Recording::setWaveform(Waveform w){
    wave = w;
}

Frequency Recording::getFreq() {
    return freq;
}

void Recording::setFreq(Frequency f) {
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

