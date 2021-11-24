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

    Waveform getWaveform();
    void setWaveform(Waveform w);

    Frequency getFreq();
    void setFreq(Frequency f);

    void incrementSecond();
    int getLength();

    void setCurrent(int c);
    int getCurrent();

    QDate* getDate();

signals:

};

#endif // RECORDING_H
