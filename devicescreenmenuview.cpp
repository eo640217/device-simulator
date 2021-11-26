#include "devicescreenmenuview.h"
#include "ui_devicescreenmenuview.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QVector>

DeviceScreenMenuView::DeviceScreenMenuView(QVector<QString> menuItems, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceScreenMenuView)
{
    ui->setupUi(this);

    this->menuItems = menuItems;

    QVBoxLayout* layout = new QVBoxLayout();
    this->setLayout(layout);

    for(int i = 0; i < menuItems.length(); i++){
        this->layout()->addWidget(new QLabel(menuItems[i]));
    }
}

DeviceScreenMenuView::~DeviceScreenMenuView()
{
    delete ui;
}
