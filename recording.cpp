#include "recording.h"
#include <QDebug>

Recording::Recording(QObject *parent) : QObject(parent)
{
    length = 0;
    wave = Waveform::ALPHA;
    freq = Frequency::POINT_FIVE;
    date = QDate::currentDate();
    current = 250;
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

QString Recording::toString() {
    QString f, w;
    switch (freq) {
        case Frequency::ONE_HUNDRED: f = "100hz"; break;
        case Frequency::POINT_FIVE: f = "0.5hz"; break;
        case Frequency::SEVENTY_SEVEN: f = "77hz"; break;
    }

    switch (wave) {
        case Waveform::ALPHA: w = "alpha"; break;
        case Waveform::BETTA: w = "betta"; break;
        case Waveform::GAMMA: w = "gamma"; break;
    }

    QString result;

    result += QString("Session: %1\n").arg(date.toString());
    result += QString("Duration: %1 minutes\n").arg(length/60);
    result += QString("Waveform: %1\n").arg(w);
    result += QString("Frequency: %1\n").arg(f);
    result += QString("Current: %1uA").arg(current);

    return result;
}

