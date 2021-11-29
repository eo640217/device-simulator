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
   int disconnectionTimer;

signals:
   void connectedChange(bool c);

};

#endif // CLIPS_H
