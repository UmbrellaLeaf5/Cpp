#include <D:/Programs/2023-2024/C++/lib/std_lib_facilities.h>
#include "vec2d.h"
#include <cmath>

int main()
{
    Vec2d v1(0.1, 0);
    Vec2d v2(5, 6);
    v1.print(); cout << " "; v2.print(); cout << endl;
    Vec2d v3 = v1 + v2;
    v3.print(); cout << endl;
    v3 = v1 - v2;
    v3.print(); cout << endl;
    v3 = v1 * 35;
    v3.print(); cout << endl;
    v1 += v2; v3 += v1;
    v3.print(); cout << endl;
    double scalar_product = v1*v2;
    cout << scalar_product << endl;
    cout << v3.length() << endl;
    keep_window_open();
}