#include "std_lib_facilities.h"
#ifndef VARIABLE_H
#define VARIABLE_H_1

struct Variable
{
    string name;
    double value;

    Variable(string n, double v) : name{n}, value{v} {}
};

#endif  // #ifndef VARIABLE_H