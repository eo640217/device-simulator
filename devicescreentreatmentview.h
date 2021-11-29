#ifndef DEVICESCREENTREATMENTVIEW_H
#define DEVICESCREENTREATMENTVIEW_H

#include <QWidget>

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
    Ui::DeviceScreenTreatmentView *ui;
};

#endif // DEVICESCREENTREATMENTVIEW_H
