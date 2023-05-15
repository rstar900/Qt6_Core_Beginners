#include <QCoreApplication>
#include "channel.h"
#include "radio.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Making a the parent will automatically destroy this radio object when application exits
    Radio boombox(&a);

    // Connect the quit signal from Radio to QCoreApplication::quit() slot to exit the application
    // Qt::Queuedonnection needed as a and boombox are running in separate threads
    QObject::connect(&boombox, &Radio::quit, &a, &QCoreApplication::quit, Qt::QueuedConnection);

    // Make an array of channel pointers
    Channel* stations[3];

    // Allocate new stations into the array
    stations[0] = new Channel(&boombox, 104, "Hit Radio");
    stations[1] = new Channel(&boombox, 94, "Rock the Party!!");
    stations[2] = new Channel(&boombox, 82, "Relax");

    while (true)
    {
        QString line;
        QTextStream qtin(stdin);

        qInfo("Enter on, off, test or quit...");
        line = qtin.readLine().trimmed().toUpper();

        if (line == "ON")
        {
            qInfo() << "Turning ON the radio...";
            // Connect the stations with the radio object
            for (int i{}; i < 3; ++i)
            {
                // stations[i] are already pointers, so no need of &
                QObject::connect(stations[i], &Channel::send, &boombox, &Radio::listen);
            }

            qInfo() << "Radio turned ON";
        }

        if (line == "OFF")
        {
            qInfo() << "Turning OFF the radio...";

            // Disconnect the radio object from channels
             for (int i{}; i < 3; ++i)
             {
                 QObject::disconnect(stations[i], &Channel::send, &boombox, &Radio::listen);
             }

            qInfo() << "Radio turned OFF";
        }

        // bradcast in this case
        if (line == "TEST")
        {
            qInfo() << "Staring Test...";

            for (int i{}; i < 3; ++i)
            {
                stations[i] -> broadcast("TESTING!!");
            }

            qInfo() << "Test complete!";
        }

        // finally exit the application as well
        if (line == "QUIT")
        {
            qInfo() << "Quitting Application...";
            emit boombox.quit();
            break; // Need to reach the a.exec() outside loop to make application quit
        }
    }

    return a.exec();
}
