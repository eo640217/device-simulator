#ifndef DEVICESCREENVIEW_H
#define DEVICESCREENVIEW_H

#include <QWidget>
#include "devicescreenmenuview.h"
#include "devicescreentreatmentview.h"
#include "screenview.h"
#include "devicescreenhistoryview.h"
#include "devicescreenoffview.h"

namespace Ui {
class DeviceScreenView;
}

class DeviceScreenView : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceScreenView(QWidget *parent = nullptr);
    ~DeviceScreenView();

private:
    Ui::DeviceScreenView *ui;
    ScreenView currentView;
    DeviceScreenMenuView* mainMenu;
    DeviceScreenTreatmentView* treatmentView;
    DeviceScreenOffView* offView;
    DeviceScreenHistoryView* historyView;
    void setActiveView(ScreenView);


public slots:
    void navigateUp();
    void navigateDown();
    void navigateLeft();
    void navigateRight();
    void select();
    void back();
    void power();
};

#endif // DEVICESCREENVIEW_H
