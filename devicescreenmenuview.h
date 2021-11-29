#ifndef DEVICESCREENMENUVIEW_H
#define DEVICESCREENMENUVIEW_H

#include <QWidget>
#include <QVector>
#include <QLabel>
#include "screenview.h"

namespace Ui {
class DeviceScreenMenuView;
}

class DeviceScreenMenuView : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceScreenMenuView(QWidget *parent = nullptr);
    void up();
    void down();
    void left();
    void right();
    ScreenView destinationView();
    ~DeviceScreenMenuView();

private:
    Ui::DeviceScreenMenuView *ui;
    QVector<QLabel*> menuItems;
    QVector<QLabel*> frequencyItems;
    QVector<QLabel*> waveformItems;
    QVector<QLabel*> treatmentTimeItems;
    int currentMenuItem;
    int currentFrequency;
    int currentWaveform;
    int currentTreatmentTime;
    void setCurrentMenuItem(int);
    void setCurrentFrequency(int);
    void setCurrentWaveform(int);
    void setCurrentTreatmentTime(int);

};

#endif // DEVICESCREENMENUVIEW_H
