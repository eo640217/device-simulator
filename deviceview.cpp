#include "deviceview.h"
#include "ui_deviceview.h"
#include <QVBoxLayout>
#include "devicescreenview.h"
#include "devicecontrolpadview.h"
#include <QLabel>
#include <QSizePolicy>

DeviceView::DeviceView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceView)
{
    ui->setupUi(this);

    QLabel* title = new QLabel("CES");
    DeviceScreenView* deviceScreenView = new DeviceScreenView();
    DeviceControlPadView* deviceControlPadView = new DeviceControlPadView();

    QVBoxLayout* deviceLayout = new QVBoxLayout();
    this->setLayout(deviceLayout);

    this->layout()->addWidget(title);
    this->layout()->addWidget(deviceScreenView);
    this->layout()->addWidget(deviceControlPadView);

}

DeviceView::~DeviceView()
{
    delete ui;
}
