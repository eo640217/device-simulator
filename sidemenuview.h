#ifndef SIDEMENUVIEW_H
#define SIDEMENUVIEW_H

#include <QWidget>
#include "cesdevice.h"

namespace Ui {
class SideMenuView;
}

class SideMenuView : public QWidget
{
    Q_OBJECT

public:
    explicit SideMenuView(CESDevice* d, QWidget *parent = nullptr);
    ~SideMenuView();

private:
    Ui::SideMenuView *ui;
    CESDevice* device;
    void updateTimeFactor();
};

#endif // SIDEMENUVIEW_H
