#include "devicescreenoffview.h"
#include "ui_devicescreenoffview.h"

DeviceScreenOffView::DeviceScreenOffView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceScreenOffView)
{
    ui->setupUi(this);

}

DeviceScreenOffView::~DeviceScreenOffView()
{
    delete ui;
}
