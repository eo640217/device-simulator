#ifndef DEVICESCREENOFFVIEW_H
#define DEVICESCREENOFFVIEW_H

#include <QWidget>

namespace Ui {
class DeviceScreenOffView;
}

class DeviceScreenOffView : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceScreenOffView(QWidget *parent = nullptr);
    ~DeviceScreenOffView();

private:
    Ui::DeviceScreenOffView *ui;
};

#endif // DEVICESCREENOFFVIEW_H
