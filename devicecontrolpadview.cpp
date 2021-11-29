#include "devicecontrolpadview.h"
#include "ui_devicecontrolpadview.h"
#include <QDebug>

DeviceControlPadView::DeviceControlPadView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceControlPadView)
{
    ui->setupUi(this);
    connect(ui->upPushButton, SIGNAL(released()), this, SLOT(handleUpButton()));
    connect(ui->downPushButton, SIGNAL(released()), this, SLOT(handleDownButton()));
    connect(ui->leftPushButton, SIGNAL(released()), this, SLOT(handleLeftButton()));
    connect(ui->rightPushButton, SIGNAL(released()), this, SLOT(handleRightButton()));
    connect(ui->selectPushButton, SIGNAL(released()), this, SLOT(handleSelectButton()));
    connect(ui->backPushButton, SIGNAL(released()), this, SLOT(handleBackButton()));
    connect(ui->powerPushButton, SIGNAL(released()), this, SLOT(handlePowerButton()));
}

void DeviceControlPadView::handleUpButton(){
    emit upPressed();
    qDebug() << "Up clicked";
}

void DeviceControlPadView::handleDownButton(){
    emit downPressed();
    qDebug() << "Down clicked";
}

void DeviceControlPadView::handleLeftButton(){
    emit leftPressed();
    qDebug() << "Left clicked";
}

void DeviceControlPadView::handleRightButton(){
    emit rightPressed();
    qDebug() << "Right clicked";
}

void DeviceControlPadView::handleSelectButton(){
    emit selectPressed();
    qDebug() << "Select clicked";
}

void DeviceControlPadView::handleBackButton(){
    emit backPressed();
    qDebug() << "Back clicked";
}

void DeviceControlPadView::handlePowerButton(){
    emit powerPressed();
    qDebug() << "Power clicked";
}



DeviceControlPadView::~DeviceControlPadView()
{
    delete ui;
}
