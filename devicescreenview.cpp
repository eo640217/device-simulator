#include "devicescreenview.h"
#include "ui_devicescreenview.h"
#include "devicescreenmenuview.h"
#include <QGridLayout>
#include <QLabel>

DeviceScreenView::DeviceScreenView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceScreenView)
{
    ui->setupUi(this);

    QVector<QString> mainMenuItems;
    mainMenuItems.append("Start");
    mainMenuItems.append("Frequencies");
    mainMenuItems.append("Waveforms");
    mainMenuItems.append("Treatment Time");
    mainMenuItems.append("History");
    DeviceScreenMenuView* mainMenu = new DeviceScreenMenuView(mainMenuItems);

    QVector<QString> frequencyMenuItems;
    frequencyMenuItems.append("0.5 Hz");
    frequencyMenuItems.append("100 Hz");
    DeviceScreenMenuView* frequencyMenu = new DeviceScreenMenuView(frequencyMenuItems);


    QLabel* circuitCheck = new QLabel( "   ⃠  ");
    QLabel* menuTitle = new QLabel("Main Menu");
    QLabel* batteryIcon = new QLabel("Battery");

    QGridLayout* layout = new QGridLayout();
    this->setLayout(layout);

    static_cast<QGridLayout*>(this->layout())->addWidget(circuitCheck, 0, 0);
    static_cast<QGridLayout*>(this->layout())->addWidget(menuTitle, 0, 1);
    static_cast<QGridLayout*>(this->layout())->addWidget(batteryIcon, 0, 2);
    static_cast<QGridLayout*>(this->layout())->addWidget(mainMenu, 1, 0, 1, 3);


}

DeviceScreenView::~DeviceScreenView()
{
    delete ui;
}
