#include "E_testing/E.h"
#include "unique_ptr/unique.h"
#include <iostream>

E* f ()
{
    Unique_ptr<E> p{new E};
    return p.release();
}

void g () { Unique_ptr<E> p{f()}; }

int main ()
{
    try
    {
        std::vector<E> v;
        v.resize(20);
        v.push_back(E());
        return 0;
    }
    catch (E_except& e)
    {
    }
}