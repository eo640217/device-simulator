#ifndef CURRENTCONTROL_H
#define CURRENTCONTROL_H

#include <QObject>

class CurrentControl : public QObject
{
    Q_OBJECT
public:
    explicit CurrentControl(QObject *parent = nullptr);
    void changeCurrent(int);
    int getCurrent();

private:
    int16_t current;
    void increaseCurrent();
    void decreaseCurrent();

signals:

};

#endif // CURRENTCONTROL_H
