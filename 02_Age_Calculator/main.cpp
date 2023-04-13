#include <QCoreApplication>
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int age;
    int dog_years = 7;
    int cat_years = 5;
    int fish_years = 18;

    std::cout << "Enter your age: ";
    std::cin >> age;

    qInfo() << "Human age:" << age;
    qInfo() << "Dog age:" << age * dog_years;
    qInfo() << "Cat age:" << age * cat_years;
    qInfo() << "Fish age:" << age * fish_years;

    return a.exec();
}
