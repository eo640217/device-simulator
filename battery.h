#ifndef BATTERY_H
#define BATTERY_H

#include <QObject>
#include <QTimer>

class Battery : public QObject
{
    Q_OBJECT
private:
    int power;
    double drain;
    QTimer drainT;

public:
    explicit Battery(QObject *parent = nullptr);
    void setDrain(double d);
    int getPower();

signals:
    void powerNotif(int power);
};

#endif // BATTERY_H
