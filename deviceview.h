#ifndef DEVICEVIEW_H
#define DEVICEVIEW_H

#include <QWidget>

namespace Ui {
class DeviceView;
}

class DeviceView : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceView(QWidget *parent = nullptr);
    ~DeviceView();

private:
    Ui::DeviceView *ui;
};

#endif // DEVICEVIEW_H
