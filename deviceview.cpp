#include "deviceview.h"
#include "ui_deviceview.h"
#include <QVBoxLayout>
#include "devicescreenview.h"
#include "devicecontrolpadview.h"
#include "sidemenuview.h"
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
    QHBoxLayout* windowLayout = new QHBoxLayout();



    this->setLayout(windowLayout);

    static_cast<QVBoxLayout*>(deviceLayout)->addWidget(title, 0, Qt::AlignCenter);
    deviceLayout->addWidget(deviceScreenView);
    deviceLayout->addWidget(deviceControlPadView);

    QWidget* main = new QWidget;

    main->setLayout(deviceLayout);

    windowLayout->addWidget(main);

    SideMenuView* sideMenuView = new SideMenuView(&device);

    windowLayout->addWidget(sideMenuView);


}

DeviceView::~DeviceView()
{
    delete ui;
}
