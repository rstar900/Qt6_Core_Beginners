#include "timertest.h"

TimerTest::TimerTest(QObject *parent)
    : QObject{parent}
{
    count = 0; // Setting count to 0
    m_qtimer.setInterval(1000); // Setting interval of 1 sec (1000 ms)
    connect(&m_qtimer, &QTimer::timeout, this, &TimerTest::timeout); // Connecting Qtimer::timeout signal with TimerTest::timeout slot
    m_qtimer.start();
}

void TimerTest::timeout()
{
    // only display Hello! 3 times
    if (count < 3)
    {
        qInfo("Hello!");
        count++;
    }
    else // stop timer and disconnect
    {
        qInfo("Done!");
        m_qtimer.stop();
        disconnect(&m_qtimer, &QTimer::timeout, this, &TimerTest::timeout);
    }
}
