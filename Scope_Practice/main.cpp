#include <QCoreApplication>
#include <QDebug>
#include <iostream>

int age{};

int addTen(int age)
{
    ::age += 10;
    return ::age;
}

void dogYears(int value)
{
    age *= 7;
    qInfo() << "Dog Years : " << age;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Enter your age : ";
    std::cin >> age;

    qInfo() << "Ten : " << addTen(age);
    dogYears(age);

    return a.exec();
}
