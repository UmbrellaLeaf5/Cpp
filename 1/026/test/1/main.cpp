#include <iostream>

struct Point
{
    int x;
    int y;
};

struct Rect
{
    Point lt;  // left top
    Point rb;  // right bottom
};

Rect* transform (const Rect* src)
{
    if (src == nullptr)
        return nullptr;
    Rect* res = new Rect;
    res->lt.x = -src->lt.y;
    res->lt.y = src->rb.x;
    res->rb.x = -src->rb.y;
    res->rb.y = src->lt.x;
    return res;
}

int main ()
{
    Rect a = {{2, 4}, {7, 1}};
    Rect* rect;
    rect = transform(&a);
    printf("%d %d %d %d\n", a.lt.x, a.lt.y, a.rb.x, a.rb.y);
    printf("%d %d %d %d\n", rect->lt.x, rect->lt.y, rect->rb.x, rect->rb.y);
    delete rect;
    return 0;
    return 0;
}