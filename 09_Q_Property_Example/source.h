#ifndef SOURCE_H
#define SOURCE_H

#include <QObject>
#include <QDebug>

class Source : public QObject
{
    Q_OBJECT
    QString m_message; // Our private member which we will get and set
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged) // can use setProperty() and other high level functions
public:
    explicit Source(QObject *parent = nullptr);

    const QString &message() const;
    void setMessage(const QString &newMessage);

signals:
    void messageChanged(QString msg);
};

#endif // SOURCE_H
