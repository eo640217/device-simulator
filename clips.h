#ifndef CLIPS_H
#define CLIPS_H

#include <QObject>
#include <QDebug>

class Clips : public QObject
{
    Q_OBJECT
public:
    explicit Clips(QObject *parent = nullptr);
    bool isConnected();
    void connect();
    void disconnect();
private:
   bool connected;
   int disconnectionTimer;

signals:

};

#endif // CLIPS_H
