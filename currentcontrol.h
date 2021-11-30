#ifndef CURRENTCONTROL_H
#define CURRENTCONTROL_H

#include <QObject>

#define STARTING_CURRENT 250

class CurrentControl : public QObject
{
    Q_OBJECT
public:
    explicit CurrentControl(QObject *parent = nullptr);

    int getCurrent();
    void increaseCurrent();
    void decreaseCurrent();
    void resetCurrent();

private:
    int current;


signals:
    void currentChanged(int);

};

#endif // CURRENTCONTROL_H
