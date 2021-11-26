#ifndef DEVICESCREENVIEW_H
#define DEVICESCREENVIEW_H

#include <QWidget>

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
};

#endif // DEVICESCREENVIEW_H
