#include <D:/Programs/2023-2024/C++/lib/std_lib_facilities.h>
#ifndef LOGIC_H
#define LOGIC_H_1


class Element;

enum class ElementType
{
    src,
    and_op,
    or_op
};

struct Input
{
    const Element& Previous;
    bool is_inverted;
};

class Element
{
    public:
        bool signal_calculate();
        bool signal = signal_calculate();
        ElementType type;
        vector<Input> Input_list;
};

bool Element::signal_calculate()
{
    switch(type)
    {
        case ElementType::src:
            return signal;
        case ElementType::and_op:
            bool res = 1;
            for(auto& in : Input_list)
            {
                res &= (in.Previous).signal;
            }
            return res;
        /*case ElementType::or_op:
            res = 0;
            for(auto& in : Input_list)
            {
                res |= (in.Previous).signal;
            }
            return res;*/
    }

}

#endif // #ifndef VEC2D_H