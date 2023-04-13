#ifndef TIMERTEST_H
#define TIMERTEST_H

#include <QObject>
#include <QDebug>
#include <QTimer>

class TimerTest : public QObject
{
    Q_OBJECT
    QTimer m_qtimer;
    int count;

public:
    explicit TimerTest(QObject *parent = nullptr);

public slots:
    void timeout();

signals:

};

#endif // TIMERTEST_H
