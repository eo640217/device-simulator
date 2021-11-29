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
