#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sidemenuview.h"
#include "deviceview.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SideMenuView* sideMenuView = new SideMenuView();
    DeviceView* deviceView = new DeviceView();

    QHBoxLayout *mainWindowLayout = new QHBoxLayout();
    QWidget *mainWidget = new QWidget();
    mainWidget->setLayout(mainWindowLayout);
    this->setCentralWidget(mainWidget);

    mainWidget->layout()->addWidget(deviceView);
    mainWidget->layout()->addWidget(sideMenuView);

}

MainWindow::~MainWindow()
{
    delete ui;
}

