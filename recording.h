#ifndef RECORDING_H
#define RECORDING_H

#include <QObject>
#include <QDate>
#include "waveform.h"
#include "frequency.h"


class Recording : public QObject
{
    Q_OBJECT

private:
    Waveform wave;
    Frequency freq;
    int length;
    int current;
    QDate date;

public:
    explicit Recording(QObject *parent = nullptr);

    void incrementSecond();
    QString toString();

    // getters / setters
    Waveform getWaveform();
    void setWaveform(Waveform w);
    Frequency getFreq();
    void setFreq(Frequency f);
    int getLength();
    void setCurrent(int c);
    int getCurrent();
    QDate* getDate();
};

#endif // RECORDING_H
