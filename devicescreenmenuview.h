#ifndef DEVICESCREENMENUVIEW_H
#define DEVICESCREENMENUVIEW_H

#include <QWidget>
#include <QVector>

namespace Ui {
class DeviceScreenMenuView;
}

class DeviceScreenMenuView : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceScreenMenuView(QVector<QString> menuItems, QWidget *parent = nullptr);
    ~DeviceScreenMenuView();

private:
    Ui::DeviceScreenMenuView *ui;
    QVector<QString> menuItems;
};

#endif // DEVICESCREENMENUVIEW_H
