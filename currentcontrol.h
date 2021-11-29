#ifndef CURRENTCONTROL_H
#define CURRENTCONTROL_H

#include <QObject>

class CurrentControl : public QObject
{
    Q_OBJECT
public:
    explicit CurrentControl(QObject *parent = nullptr);

    int getCurrent();
    void increaseCurrent();
    void decreaseCurrent();

private:
    int current;


signals:
    void currentChanged(int);

};

#endif // CURRENTCONTROL_H
