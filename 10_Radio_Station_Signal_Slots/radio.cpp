#include "radio.h"

Radio::Radio(QObject *parent)
    : QObject{parent}
{

}

void Radio::listen(int channel_no, QString channel_name, QString msg)
{
    qInfo() << channel_no << " - " << channel_name << " - " << msg;
}
