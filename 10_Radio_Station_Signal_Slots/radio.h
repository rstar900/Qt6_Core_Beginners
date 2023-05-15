#ifndef RADIO_H
#define RADIO_H

#include <QObject>
#include <QDebug>

class Radio : public QObject
{
    Q_OBJECT
public:
    explicit Radio(QObject *parent = nullptr);

signals:
    void quit(); // to close the application

public slots:
    void listen(int channel_no, QString channel_name, QString msg);
};

#endif // RADIO_H
