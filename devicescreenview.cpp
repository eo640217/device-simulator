#include "devicescreenview.h"
#include "ui_devicescreenview.h"
#include "devicescreenmenuview.h"
#include "screenview.h"
#include <QGridLayout>
#include <QLabel>
#include <QDebug>
#include <QWidget>
#include <QVBoxLayout>

DeviceScreenView::DeviceScreenView(CESDevice* d, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceScreenView)
{
    ui->setupUi(this);

    device = d;

    this->treatmentView = new DeviceScreenTreatmentView();
    this->mainMenu = new DeviceScreenMenuView(device);
    this->historyView = new DeviceScreenHistoryView(this->device->getRecordings());
    this->offView = new DeviceScreenOffView();

    QWidget* content = new QWidget();
    content->setLayout(new QVBoxLayout());
    content->layout()->addWidget(mainMenu);
    content->layout()->addWidget(treatmentView);
    content->layout()->addWidget(historyView);
    content->layout()->addWidget(offView);
    this->setActiveView(ScreenView::OFF);

    toggleStatusBar(false);

    QGridLayout* layout = new QGridLayout();
    this->setLayout(layout);

    static_cast<QGridLayout*>(this->layout())->addWidget(this->ui->TestCircuit, 0, 0);
    static_cast<QGridLayout*>(this->layout())->addWidget(this->ui->MenuLabel, 0, 1, Qt::AlignCenter);
    static_cast<QGridLayout*>(this->layout())->addWidget(this->ui->BatteryLevel, 0, 2, Qt::AlignRight);
    static_cast<QGridLayout*>(this->layout())->addWidget(content, 1, 0, 1, 3);

    connect(device, &CESDevice::powerStatus, this, &DeviceScreenView::batteryUpdate);
    connect(device, &CESDevice::shuttingDown, this, &DeviceScreenView::idleShutdown);


}

void DeviceScreenView::setActiveView(ScreenView view){
    this->currentView = view;

    // Hide all views
    this->mainMenu->hide();
    this->treatmentView->hide();
    this->historyView->hide();
    this->offView->hide();

    // Show active view
    if(view == ScreenView::MAIN_MENU){
        this->mainMenu->show();
    } else if(view == ScreenView::TREATMENT){
        this->treatmentView->show();
    } else if(view == ScreenView::HISTORY) {
        this->historyView->show();
    } else if(view == ScreenView::OFF) {
        this->offView->show();
    }
}

void DeviceScreenView::navigateUp(){
    if(this->currentView == ScreenView::MAIN_MENU){
        this->mainMenu->up();
    } else if(this->currentView == ScreenView::TREATMENT){
        // increase current
        this->device->getCController()->increaseCurrent();
    }
}

void DeviceScreenView::navigateDown(){
    if(this->currentView == ScreenView::MAIN_MENU){
        this->mainMenu->down();
    } else if(this->currentView == ScreenView::TREATMENT){
        this->device->getCController()->decreaseCurrent();
    } else if(this->currentView == ScreenView::HISTORY){
        // Handle treatment
    }
}

void DeviceScreenView::navigateLeft(){
    if(this->currentView == ScreenView::MAIN_MENU){
        this->mainMenu->left();
    }
//    else if(this->currentView == ScreenView::TREATMENT){
//        // Handle treatment
//    } else if(this->currentView == ScreenView::HISTORY){
//        // Handle history
//    }
}

void DeviceScreenView::navigateRight(){
    if(this->currentView == ScreenView::MAIN_MENU){
        this->mainMenu->right();
    }
//    else if(this->currentView == ScreenView::TREATMENT){
//        // Handle treatment
//    } else if(this->currentView == ScreenView::HISTORY){
//        // Handle history
//    }
}

void DeviceScreenView::select(){
    if(this->currentView == ScreenView::MAIN_MENU){
        this->setActiveView(this->mainMenu->destinationView());
    }
//    else if(this->currentView == ScreenView::TREATMENT){
//        // Handle treatment
//    } else if(this->currentView == ScreenView::HISTORY){
//        // Handle history
//    }
}

void DeviceScreenView::back(){
    if(this->currentView == ScreenView::MAIN_MENU){
        // Handle main
    } else if(this->currentView == ScreenView::TREATMENT){
        //this->setActiveView(ScreenView::MAIN_MENU);
    } else if(this->currentView == ScreenView::HISTORY){
        this->setActiveView(ScreenView::MAIN_MENU);
    }
}

void DeviceScreenView::power(){
    if (device->getStatus() == DeviceStatus::OFF) {
        setActiveView(ScreenView::MAIN_MENU);
        device->powerOn();
        toggleStatusBar(true);
        return;
    }

    device->shutdown();
    this->setActiveView(ScreenView::OFF);
    toggleStatusBar(false);
}

void DeviceScreenView::batteryUpdate(int p) {
    this->ui->BatteryLevel->setValue(p);
}

void DeviceScreenView::toggleStatusBar(bool b) {
    ui->BatteryLevel->setVisible(b);
    ui->MenuLabel->setVisible(b);
    ui->TestCircuit->setVisible(b);
}

void DeviceScreenView::idleShutdown() {
    this->setActiveView(ScreenView::OFF);
    toggleStatusBar(false);
}


DeviceScreenView::~DeviceScreenView()
{
    delete ui;
}
