#include "sidemenuview.h"
#include "ui_sidemenuview.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>

SideMenuView::SideMenuView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SideMenuView)
{
    ui->setupUi(this);

    QVBoxLayout* layout = new QVBoxLayout();
    this->setLayout(layout);

    QWidget* electrodesMenuItem = new QWidget();
    electrodesMenuItem->setLayout(new QHBoxLayout());
    QLabel* electrodeLabel = new QLabel("Electrodes touch skin");
    QCheckBox* electrodeCheckBox = new QCheckBox();
    electrodesMenuItem->layout()->addWidget(electrodeLabel);
    electrodesMenuItem->layout()->addWidget(electrodeCheckBox);

    this->layout()->addWidget(electrodesMenuItem);

}

SideMenuView::~SideMenuView()
{
    delete ui;
}
