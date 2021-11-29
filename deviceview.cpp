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
    DeviceScreenView* deviceScreenView = new DeviceScreenView(&device);
    DeviceControlPadView* deviceControlPadView = new DeviceControlPadView();

    connect(deviceControlPadView, SIGNAL(upPressed()), deviceScreenView, SLOT(navigateUp()));
    connect(deviceControlPadView, SIGNAL(downPressed()), deviceScreenView, SLOT(navigateDown()));
    connect(deviceControlPadView, SIGNAL(leftPressed()), deviceScreenView, SLOT(navigateLeft()));
    connect(deviceControlPadView, SIGNAL(rightPressed()), deviceScreenView, SLOT(navigateRight()));
    connect(deviceControlPadView, SIGNAL(backPressed()), deviceScreenView, SLOT(back()));
    connect(deviceControlPadView, SIGNAL(selectPressed()), deviceScreenView, SLOT(select()));
    connect(deviceControlPadView, SIGNAL(powerPressed()), deviceScreenView, SLOT(power()));



    QVBoxLayout* deviceLayout = new QVBoxLayout();
    this->setLayout(deviceLayout);

    static_cast<QVBoxLayout*>(this->layout())->addWidget(title, 0, Qt::AlignCenter);
    this->layout()->addWidget(deviceScreenView);
    this->layout()->addWidget(deviceControlPadView);

}

DeviceView::~DeviceView()
{
    delete ui;
}
