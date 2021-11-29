#ifndef DEVICESCREENMENUVIEW_H
#define DEVICESCREENMENUVIEW_H

#include <QWidget>
#include <QVector>
#include <QLabel>
#include "screenview.h"
#include "cesdevice.h"

namespace Ui {
class DeviceScreenMenuView;
}

class DeviceScreenMenuView : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceScreenMenuView(CESDevice* d, QWidget *parent = nullptr);
    void up();
    void down();
    void left();
    void right();
    ScreenView destinationView();
    ~DeviceScreenMenuView();

private:
    CESDevice* device;
    Ui::DeviceScreenMenuView *ui;
    QVector<QLabel*> menuItems;
    QVector<QLabel*> frequencyItems;
    QVector<QLabel*> waveformItems;
    QVector<QLabel*> treatmentTimeItems;
    QVector<QLabel*> saveRecordingItems;
    int currentMenuItem;
    int currentFrequency;
    int currentWaveform;
    int currentTreatmentTime;
    int currentSaveRecording;
    void setCurrentMenuItem(int);
    void setCurrentFrequency(int);
    void setCurrentWaveform(int);
    void setCurrentTreatmentTime(int);
    void setCurrentSaveRecording(int);

};

#endif // DEVICESCREENMENUVIEW_H
