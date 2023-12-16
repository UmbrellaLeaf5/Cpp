#include <Tracer_lib/tracer.h>
#include <iostream>
#include <vector>

struct X
{
    X() { TRACE_FUNC; }

    X(const X&) { TRACE_FUNC; }

    ~X() { TRACE_FUNC; }

    X(int n)
    {
        TRACE_FUNC;
        std::cout << "n = " << n << std::endl;
    }
};

int main ()

{
    int n = 3;
    std::vector<X> v(n, X(5));
    std::cout << std::endl << std::endl;
    v.resize(4 * n);
    std::cout << std::endl << std::endl;
    v.back() = X();
    std::cout << std::endl << std::endl;
    v.resize(n * n, X(10));
    std::cout << std::endl << std::endl;
    v.back() = X();
    std::cout << std::endl << std::endl;
    v.clear();
    std::cout << std::endl << std::endl;
    v[2] = X(3);
}