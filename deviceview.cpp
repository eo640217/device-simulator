#include "deviceview.h"
#include "ui_deviceview.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QSizePolicy>
#include <QFrame>

DeviceView::DeviceView(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DeviceView)
{
    ui->setupUi(this);

    this->setStyleSheet("QFrame#DeviceView{background-color: #333333; border: 2px solid #000;}");

    QLabel* title = new QLabel("CES");
    title->setStyleSheet("font-size: 20px; font-weight: bold");
    deviceScreenView = new DeviceScreenView(&device);
    deviceControlPadView = new DeviceControlPadView();

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
    //title->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    deviceScreenView->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Expanding);
    static_cast<QVBoxLayout*>(deviceLayout)->addWidget(title, 0, Qt::AlignCenter);
    deviceLayout->addWidget(deviceScreenView);
    deviceLayout->addWidget(deviceControlPadView);

    QFrame* main = new QFrame;
    main->setObjectName("main");
    main->setStyleSheet("QFrame#main{border-radius: 20px; border: 8px solid #000; background-color: #b3b3b3}");

    main->setLayout(deviceLayout);

    windowLayout->addWidget(main);

    sideMenuView = new SideMenuView(&device);

    windowLayout->addWidget(sideMenuView);


}

DeviceView::~DeviceView()
{
    delete ui;
}
