#include "devicescreenhistoryview.h"
#include "ui_devicescreenhistoryview.h"

DeviceScreenHistoryView::DeviceScreenHistoryView(QList<Recording*>* r, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceScreenHistoryView)
{
    ui->setupUi(this);
    recordings = r;

    ui->RecordingCount->setText(QString("%1 Recordings").arg(recordings->length()));

}

DeviceScreenHistoryView::~DeviceScreenHistoryView()
{
    delete ui;
}
