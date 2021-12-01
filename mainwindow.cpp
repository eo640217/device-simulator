#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "deviceview.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DeviceView* deviceView = new DeviceView();

    setCentralWidget(deviceView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

