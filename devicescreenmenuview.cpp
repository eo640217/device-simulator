#include "devicescreenmenuview.h"
#include "ui_devicescreenmenuview.h"
#include <QGridLayout>
#include <QLabel>
#include <QVector>
#include <QDebug>
#include <QPalette>

DeviceScreenMenuView::DeviceScreenMenuView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceScreenMenuView)
{
    ui->setupUi(this);

    //Main menu options to choose from
    QVector<QString> mainMenuItems;
    mainMenuItems.append("Start");
    mainMenuItems.append("Frequencies");
    mainMenuItems.append("Waveforms");
    mainMenuItems.append("Treatment Time");
    mainMenuItems.append("History");

    //Frequency options to choose from
    QVector<QString> frequencyMenuItems;
    frequencyMenuItems.append("0.5 Hz");
    frequencyMenuItems.append("75 Hz");
    frequencyMenuItems.append("100 Hz");

    //Waveform options to choose from
    QVector<QString> waveformMenuItems;
    waveformMenuItems.append("Alpha");
    waveformMenuItems.append("Betta");
    waveformMenuItems.append("Gamma");

    //Treatment time options to choose from
    QVector<QString> treatmentTimeMenuItems;
    treatmentTimeMenuItems.append("20 minutes");
    treatmentTimeMenuItems.append("40 minutes");
    treatmentTimeMenuItems.append("60 minutes");

    QGridLayout* layout = new QGridLayout();
    this->setLayout(layout);

    for(int i = 0; i < mainMenuItems.length(); i++){
        this->menuItems.append(new QLabel(mainMenuItems[i]));
        static_cast<QGridLayout*>(this->layout())->addWidget(this->menuItems[i], i, 0);
    }

    for(int i = 0; i < frequencyMenuItems.length(); i++){
        this->frequencyItems.append(new QLabel(frequencyMenuItems[i]));
        static_cast<QGridLayout*>(this->layout())->addWidget(this->frequencyItems[i], 1, 1, Qt::AlignRight);
    }

    for(int i = 0; i < waveformMenuItems.length(); i++){
        this->waveformItems.append(new QLabel(waveformMenuItems[i]));
        static_cast<QGridLayout*>(this->layout())->addWidget(this->waveformItems[i], 2, 1, Qt::AlignRight);
    }

    for(int i = 0; i < treatmentTimeMenuItems.length(); i++){
        this->treatmentTimeItems.append(new QLabel(treatmentTimeMenuItems[i]));
        static_cast<QGridLayout*>(this->layout())->addWidget(this->treatmentTimeItems[i], 3, 1, Qt::AlignRight);
    }

    this->setCurrentMenuItem(0);
    this->setCurrentFrequency(0);
    this->setCurrentWaveform(0);
    this->setCurrentTreatmentTime(0);
}

void DeviceScreenMenuView::up(){
    this->setCurrentMenuItem(this->currentMenuItem - 1 >= 0 ? this->currentMenuItem - 1 : this->menuItems.length() - 1);
}

void DeviceScreenMenuView::down(){
    this->setCurrentMenuItem((this->currentMenuItem + 1) % this->menuItems.length());
}

void DeviceScreenMenuView::left(){
    if(this->currentMenuItem == 1){
        this->setCurrentFrequency(this->currentFrequency - 1);
    } else if(this->currentMenuItem == 2){
        this->setCurrentWaveform(this->currentWaveform - 1);
    } else if(this->currentMenuItem == 3){
        this->setCurrentTreatmentTime(this->currentTreatmentTime - 1);
    }
}

void DeviceScreenMenuView::right(){
    if(this->currentMenuItem == 1){
        this->setCurrentFrequency(this->currentFrequency + 1);
    } else if(this->currentMenuItem == 2){
        this->setCurrentWaveform(this->currentWaveform + 1);
    } else if(this->currentMenuItem == 3){
        this->setCurrentTreatmentTime(this->currentTreatmentTime + 1);
    }
}

ScreenView DeviceScreenMenuView::destinationView(){
    if(this->currentMenuItem == 0){
        return ScreenView::TREATMENT;
    } else if(this->currentMenuItem == 4){
        return ScreenView::HISTORY;
    }

    return ScreenView::MAIN_MENU;
}

void DeviceScreenMenuView::setCurrentMenuItem(int menuItem){
    this->currentMenuItem = menuItem;
    for(int i = 0; i < this->menuItems.length(); i++){
        QPalette palette = this->menuItems[i]->palette();

        if(i == menuItem){
            palette.setColor(this->menuItems[i]->foregroundRole(), Qt::blue);
        } else {
            palette.setColor(this->menuItems[i]->foregroundRole(), Qt::black);
        }

        this->menuItems[i]->setPalette(palette);

    }

}

void DeviceScreenMenuView::setCurrentFrequency(int frequency){
    if(frequency >= 0 && frequency < this->frequencyItems.length()){
        this->currentFrequency = frequency;
        for(int i = 0; i < this->frequencyItems.length(); i++){
            if(i == frequency){
                this->frequencyItems[i]->show();
            } else {
                this->frequencyItems[i]->hide();
            }
        }
    }
}

void DeviceScreenMenuView::setCurrentWaveform(int waveform){
    if(waveform >= 0 && waveform < this->waveformItems.length()){
        this->currentWaveform = waveform;
        for(int i = 0; i < this->waveformItems.length(); i++){
            if(i == waveform){
                this->waveformItems[i]->show();
            } else {
                this->waveformItems[i]->hide();
            }
        }
    }
}

void DeviceScreenMenuView::setCurrentTreatmentTime(int treatmentTime){
    if(treatmentTime >= 0 && treatmentTime < this->treatmentTimeItems.length()){
        this->currentTreatmentTime = treatmentTime;
        for(int i = 0; i < this->treatmentTimeItems.length(); i++){
            if(i == treatmentTime){
                this->treatmentTimeItems[i]->show();
            } else {
                this->treatmentTimeItems[i]->hide();
            }
        }
    }
}

DeviceScreenMenuView::~DeviceScreenMenuView()
{
    delete ui;
}
