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

private slots:
    void handleUpButton();
    void handleDownButton();
    void handleLeftButton();
    void handleRightButton();
    void handleSelectButton();
    void handleBackButton();
    void handlePowerButton();

signals:
    void upPressed();
    void downPressed();
    void leftPressed();
    void rightPressed();
    void selectPressed();
    void backPressed();
    void powerPressed();
};

#endif // DEVICECONTROLPADVIEW_H
