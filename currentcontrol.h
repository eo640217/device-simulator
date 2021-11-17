#ifndef CURRENTCONTROL_H
#define CURRENTCONTROL_H

#include <QObject>

class CurrentControl : public QObject
{
    Q_OBJECT
public:
    explicit CurrentControl(QObject *parent = nullptr);

signals:

};

#endif // CURRENTCONTROL_H
