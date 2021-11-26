#include "devicecontrolpadview.h"
#include "ui_devicecontrolpadview.h"

DeviceControlPadView::DeviceControlPadView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceControlPadView)
{
    ui->setupUi(this);
}

DeviceControlPadView::~DeviceControlPadView()
{
    delete ui;
}
