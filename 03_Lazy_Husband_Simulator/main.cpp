#include <QCoreApplication>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString task = "Please take out the trash";
    int max = 5;

    for (int i = 1; i <= 50; i++)
    {
        qInfo() << "Wife:" << task;
        qWarning() << "Wife: I have asked it" << i << "times";

        if (i >= max)
        {
            qInfo() << "Husband: Ok, ok, I am going ...";
            break;
        }
    }

    return a.exec();
}
