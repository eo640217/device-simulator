#ifndef DEVICEVIEW_H
#define DEVICEVIEW_H

#include "cesdevice.h"
#include "devicescreenview.h"
#include "devicecontrolpadview.h"
#include "sidemenuview.h"

#include <QWidget>
#include <QFrame>

namespace Ui {
class DeviceView;
}

class DeviceView : public QFrame
{
    Q_OBJECT

public:
    explicit DeviceView(QWidget *parent = nullptr);
    ~DeviceView();

private:
    Ui::DeviceView *ui;
    CESDevice device;
    DeviceScreenView* deviceScreenView;
    DeviceControlPadView* deviceControlPadView;
    SideMenuView* sideMenuView;
};

#endif // DEVICEVIEW_H
