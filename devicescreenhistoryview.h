#ifndef DEVICESCREENHISTORYVIEW_H
#define DEVICESCREENHISTORYVIEW_H

#include "recording.h"
#include <QList>

#include <QWidget>

namespace Ui {
class DeviceScreenHistoryView;
}

class DeviceScreenHistoryView : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceScreenHistoryView(QList<Recording*>* r, QWidget *parent = nullptr);
    ~DeviceScreenHistoryView();

private:
    QList<Recording*>* recordings;
    Ui::DeviceScreenHistoryView *ui;
};

#endif // DEVICESCREENHISTORYVIEW_H
