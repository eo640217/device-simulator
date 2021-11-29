#ifndef SIDEMENUVIEW_H
#define SIDEMENUVIEW_H

#include <QWidget>

namespace Ui {
class SideMenuView;
}

class SideMenuView : public QWidget
{
    Q_OBJECT

public:
    explicit SideMenuView(QWidget *parent = nullptr);
    ~SideMenuView();

private:
    Ui::SideMenuView *ui;
};

#endif // SIDEMENUVIEW_H
