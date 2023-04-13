#include <QCoreApplication>
#include <iostream>
#include "calc.h"

Calc* getCalc()
{
    return new Calc();
}

int dogYears(int age, Calc* c)
{
    return c->dogYears(age);
}

int catYears(int age, Calc* c)
{
    return c->catYears(age);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // making a Calc object on heap using getCalc() function
    Calc* calc = getCalc(); // optionally getCalc(&a) so that no delete is needed as 'a' is parent

    int age{};

    qInfo() << "Enter your age:";
    std::cin >> age;

    qInfo() << "Dog years:" << dogYears(age, calc);
    qInfo() << "Cat years:" << catYears(age, calc);

    // Since we made calc on heap, we have to delete it ourselves (IMPORTANT to avoid memory leaks!)
    delete calc;

    return a.exec();
}
