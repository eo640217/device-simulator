#include "devicescreenhistoryview.h"
#include "ui_devicescreenhistoryview.h"

DeviceScreenHistoryView::DeviceScreenHistoryView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceScreenHistoryView)
{
    ui->setupUi(this);
}

DeviceScreenHistoryView::~DeviceScreenHistoryView()
{
    delete ui;
}
