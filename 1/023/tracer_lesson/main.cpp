#include "Tracer_lib/tracer.h"
#include <iostream>
#include <vector>

struct X
{
    X(int i) : val{i}
    {
        TRACE_FUNC;
        out(val);
    }

    X(const X& obj)
    {
        TRACE_FUNC;
        out(obj.val);
    }

    void out (int i) { std::cout << i << std::endl; }

  private:
    int val{0};
};

int factorial (int n)
{
    // TRACE("factorial of " + std::to_string(n));
    TRACE_FUNC;
    if (n <= 0)
        return 1;
    return n * factorial(n - 1);
}

int main ()
{
    X x{5};
    X y = x;
    std::cout << factorial(5);
}