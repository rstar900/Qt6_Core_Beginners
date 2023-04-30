#include <QCoreApplication>
#include <QVariant> // can take any value type
#include "source.h"
#include "destination.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Source s;
    Destination d;

    // Still need to connect signal and slots in C++
    QObject::connect(&s, &Source::messageChanged, &d, &Destination::messageChanged);

    // Due to Q_PROPERTY, a higher level function can be used to set and emit messageChanged signal
    s.setProperty("message", QVariant("Wow! If you see this then Q_PROPERTY works!!"));

    // Can still manually call the setMessage() getter for the same effect
    s.setMessage("Wow! If you see this then manually calling setMessage() works as well!!");
    return a.exec();
}
