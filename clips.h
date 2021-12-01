#ifndef CLIPS_H
#define CLIPS_H

#include <QObject>
#include <QDebug>

class Clips : public QObject
{
    Q_OBJECT
public:
    explicit Clips(QObject *parent = nullptr);
    bool getConnected();
    void setConnected(bool c);

private:
   bool connected;

};

#endif // CLIPS_H
