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
   // these values come in as ms convert them to s
   s = s / 1000;
   t = t / 1000;
   secondsToCountdown(s);
   auto time = countdown.addSecs(-t);
   QString strCT = time.toString("hh:mm:ss");
   this->ui->lcdNumber->display(strCT);
}

void DeviceScreenTreatmentView::secondsToCountdown(int sec)
{
    // simpler time calc
    int hour = (sec / 60) / 60;
    int min = (sec - 60*60*hour) / 60;
    sec = sec - 60*min - 60*60*hour;

    countdown.setHMS(hour, min, sec);
}
