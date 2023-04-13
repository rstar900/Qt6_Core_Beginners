#include <QCoreApplication>
#include "timertest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TimerTest timertest; // Initialization is enough as connection logic resides inside constructor

    return a.exec();
}
