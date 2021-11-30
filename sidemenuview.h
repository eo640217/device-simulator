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
    CESDevice* device;
    Ui::SideMenuView *ui;
    void updateTimeFactor();
};

#endif // SIDEMENUVIEW_H
