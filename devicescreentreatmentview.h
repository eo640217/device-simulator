#ifndef DEVICESCREENTREATMENTVIEW_H
#define DEVICESCREENTREATMENTVIEW_H

#include <QWidget>
#include "cesdevice.h"
#include <QDebug>
#include <QTimer>

namespace Ui {
class DeviceScreenTreatmentView;
}

class DeviceScreenTreatmentView : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceScreenTreatmentView(QWidget *parent = nullptr);
    ~DeviceScreenTreatmentView();

private:
    CESDevice* device;
    Ui::DeviceScreenTreatmentView *ui;
    QTime countdown;
    void secondsToCountdown(int);

public slots:
    void updateCurrent(int c);
    void updateShutdownTimer(int s, int t);
};

#endif // DEVICESCREENTREATMENTVIEW_H
