#pragma once
#include <Tracer_lib/tracer.h>
#include <vector>

struct E_except
{
};

class E
{
    static size_t count;
    static constexpr unsigned int max_count = 10;

    void counter ();

  public:
    E();

    E(E&& e);

    ~E();
};
