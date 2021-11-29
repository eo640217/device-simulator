#include "devicescreenhistoryview.h"
#include "ui_devicescreenhistoryview.h"

DeviceScreenHistoryView::DeviceScreenHistoryView(QList<Recording*>* r, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceScreenHistoryView)
{
    ui->setupUi(this);
    recordings = r;

    selected = 0;
}

void DeviceScreenHistoryView::refreshData() {
    ui->RecordingCount->setText(QString("%1 Recordings").arg(recordings->length()));

    if (recordings->length() == 0) {
        return;
    }
    ui->listWidget->clear();

    for (int x=0; x < recordings->length(); x++) {
        ui->listWidget->addItem(recordings->at(x)->toString());
    }

    ui->listWidget->item(0)->setSelected(true);
    ui->listWidget->setCurrentItem(ui->listWidget->item(0));

}

void DeviceScreenHistoryView::down() {
    if (recordings->length() == 0) {
        return;
    }
    selected = (selected + 1) % recordings->length();
    ui->listWidget->item(selected)->setSelected(true);
    ui->listWidget->setCurrentItem(ui->listWidget->item(selected));
}

void DeviceScreenHistoryView::up() {
    if (recordings->length() == 0) {
        return;
    }

    selected = (selected - 1) % recordings->length();
    ui->listWidget->item(selected)->setSelected(true);
    ui->listWidget->setCurrentItem(ui->listWidget->item(selected));

}

DeviceScreenHistoryView::~DeviceScreenHistoryView()
{
    delete ui;
}
