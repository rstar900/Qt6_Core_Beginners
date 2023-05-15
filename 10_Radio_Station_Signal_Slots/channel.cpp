#include "channel.h"

Channel::Channel(QObject *parent, int channel_no, QString channel_name) : QObject{parent}
{
    m_channel_no  = channel_no;
    m_channel_name = channel_name;
}

void Channel::broadcast(QString msg)
{
    emit send(m_channel_no, m_channel_name, msg);
}
