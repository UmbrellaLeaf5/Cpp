#include "std_lib_facilities.h"
#include "inheritance.h"

int main() 
{
    A a;
    B b;
    // вызываются совершенно разные функции
    // Print() из A сокрылась
    a.Print(); // A
    b.Print(); // B

    ShowInf(a); // A
    ShowInf(b); // B (если есть virtual)
    return 0;
}