#include "devicescreentreatmentview.h"
#include "ui_devicescreentreatmentview.h"

DeviceScreenTreatmentView::DeviceScreenTreatmentView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceScreenTreatmentView)
{
    ui->setupUi(this);
}

DeviceScreenTreatmentView::~DeviceScreenTreatmentView()
{
    delete ui;
}

void DeviceScreenTreatmentView::updateCurrent(int c)
{
    this->ui->progressBar->setValue(c);
}

void DeviceScreenTreatmentView::updateShutdownTimer(int s, int t)
{
   secondsToCountdown(s);
   auto time = countdown.addSecs(-t);
   QString strCT = time.toString("hh:mm:ss");
   this->ui->lcdNumber->display(strCT);
}

void DeviceScreenTreatmentView::secondsToCountdown(int sec)
{
    sec = sec / 5 / 100;
    int min = 0;
    int hour = 0;
    while (sec - 60 >= 0)
    {
        sec = sec - 60;
        min++;
        if(min >= 60) {
            min -= 60;
            hour++;
        }
    }
    countdown.setHMS(hour, min, sec);
}
