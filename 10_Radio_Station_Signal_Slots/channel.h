#ifndef CHANNEL_H
#define CHANNEL_H

#include <QObject>

class Channel : public QObject
{
    Q_OBJECT
    int m_channel_no;
    QString m_channel_name;
public:
    explicit Channel(QObject *parent = nullptr, int channel_no = 0, QString channel_name = "UNKNOWN");
    void broadcast(QString msg);
signals:
    void send (int channel_no, QString channel_name, QString msg); // will be emitted by broadcast method
};

#endif // CHANNEL_H
