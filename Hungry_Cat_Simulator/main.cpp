#include <QCoreApplication>
#include "cat.h"

// will not work if called
void test_fail(Cat c)
{
    c.meow();
}

void test_pointer(Cat* c)
{
    c->meow();
}

void test_reference(Cat& c)
{
    c.meow();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cat myCat;

    myCat.meow();

    // test_fail(myCat); will not work
    test_pointer(&myCat);
    test_reference(myCat);


    return a.exec();
}
