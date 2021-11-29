#ifndef DEVICESCREENVIEW_H
#define DEVICESCREENVIEW_H

#include <QWidget>
#include "devicescreenmenuview.h"
#include "devicescreentreatmentview.h"
#include "screenview.h"
#include "devicescreenhistoryview.h"
#include "devicescreenoffview.h"
#include "cesdevice.h"

namespace Ui {
class DeviceScreenView;
}

class DeviceScreenView : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceScreenView(CESDevice* d, QWidget *parent = nullptr);
    ~DeviceScreenView();

private:
    Ui::DeviceScreenView *ui;
    ScreenView currentView;
    DeviceScreenMenuView* mainMenu;
    DeviceScreenTreatmentView* treatmentView;
    DeviceScreenOffView* offView;
    DeviceScreenHistoryView* historyView;
    CESDevice* device;
    void setActiveView(ScreenView);
    void toggleStatusBar(bool b);


public slots:
    void navigateUp();
    void navigateDown();
    void navigateLeft();
    void navigateRight();
    void select();
    void back();
    void power();
    void batteryUpdate(int p);
    void idleShutdown();
    void onClipChange(bool c);
};

#endif // DEVICESCREENVIEW_H
