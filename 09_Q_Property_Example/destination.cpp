#include "destination.h"

Destination::Destination(QObject *parent)
    : QObject{parent}
{

}

void Destination::messageChanged(QString msg)
{
    qInfo() << "New Message: " << msg;
}
