#include "source.h"

const QString &Source::message() const
{
    return m_message;
}

void Source::setMessage(const QString &newMessage)
{
    m_message = newMessage;
    emit messageChanged(newMessage); // still need to emit in setter, despite the NOTIFY thing
}

Source::Source(QObject *parent)
    : QObject{parent}
{

}
