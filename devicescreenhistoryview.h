#ifndef DEVICESCREENHISTORYVIEW_H
#define DEVICESCREENHISTORYVIEW_H

#include <QWidget>

namespace Ui {
class DeviceScreenHistoryView;
}

class DeviceScreenHistoryView : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceScreenHistoryView(QWidget *parent = nullptr);
    ~DeviceScreenHistoryView();

private:
    Ui::DeviceScreenHistoryView *ui;
};

#endif // DEVICESCREENHISTORYVIEW_H
