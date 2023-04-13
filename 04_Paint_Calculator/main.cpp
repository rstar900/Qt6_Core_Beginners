#include <QCoreApplication>
#include <QDebug>
#include <iostream>

void getSize(float& wallSize)
{
    qInfo() << "Enter in feet:";
    std::cin >> wallSize;

    if (wallSize < 0)
        qFatal("Please read the manual");
}

float calcPaint(float w, float h)
{
    float squareFootPerGallon = 325;
    return (w * h) / squareFootPerGallon;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    float ceilSize, wallSize, paintInGallons = 0; // ceilSize is height and wallSize is width

    qInfo() << "Add a ceiling";
    getSize(ceilSize);


    while(true)
    {
        qInfo() << "Add a wall by entering a number and 0 to stop";
        getSize(wallSize);

        if (wallSize == 0)
            break;

        paintInGallons += calcPaint(wallSize, ceilSize);
    }

    qInfo() << "Paint in gallons:" << paintInGallons;

    return a.exec();
}
