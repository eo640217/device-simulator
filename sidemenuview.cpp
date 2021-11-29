#include "sidemenuview.h"
#include "ui_sidemenuview.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QSlider>

SideMenuView::SideMenuView(CESDevice* d, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SideMenuView)
{
    ui->setupUi(this);

    device = d;

    connect(ui->ClipCheckbox, &QCheckBox::toggled, device, &CESDevice::onClipChange);
    connect(ui->TimeSlider, &QSlider::sliderReleased, this, &SideMenuView::updateTimeFactor);
    connect(ui->ChargeButton, &QPushButton::clicked, device->getBattery(), &Battery::onCharge);
    connect(ui->OverloadButton, &QPushButton::clicked, device, &CESDevice::overload);


}

void SideMenuView::updateTimeFactor() {
    ui->TimeLabel->setText(QString("%1x").arg(ui->TimeSlider->value()));

    device->updateTimeFactor(ui->TimeSlider->value());
}

SideMenuView::~SideMenuView()
{
    delete ui;
}
