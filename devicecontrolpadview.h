#ifndef DEVICECONTROLPADVIEW_H
#define DEVICECONTROLPADVIEW_H

#include <QWidget>

namespace Ui {
class DeviceControlPadView;
}

class DeviceControlPadView : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceControlPadView(QWidget *parent = nullptr);
    ~DeviceControlPadView();

private:
    Ui::DeviceControlPadView *ui;
};

#endif // DEVICECONTROLPADVIEW_H
