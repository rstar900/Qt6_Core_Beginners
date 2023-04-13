#include <QCoreApplication>
#include <QDebug>
#include <iostream>

int addTen(int age)
{
    return age + 10;
}

void dogYears(int value)
{
    int age = value * 7;
    qInfo() << "Dog Years : " << age;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int age {};

    qInfo() << "Enter your age : ";
    std::cin >> age;

    age = addTen(age);
    qInfo() << "Ten : " << age;
    dogYears(age);

    return a.exec();
}
