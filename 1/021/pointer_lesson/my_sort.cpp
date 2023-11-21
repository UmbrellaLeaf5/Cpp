#include "my_sort.h"
#include <stdexcept>

void merge_sort (int* begin, int* end)
{
    if (!begin || !end)
        throw std::invalid_argument{"merge_sort: null pointer received"};
    if (begin == end)
        return;
    else if (end < begin)
        throw std::invalid_argument{"merge_sort: invalid range"};
    else
    {
        int* buf = new int[end - begin];  // создание временного массива из end - begin элементов
        merge_sort_impl(begin, end, buf);
        delete[] buf;
    }
}

void merge_sort_impl (int* begin, int* end, int* buf)
{
    if (end - begin <= 1)
        return;
    int* middle = begin + (end - begin) / 2;
    merge_sort_impl(begin, middle, buf);
    merge_sort_impl(middle, end, buf);
    merge(begin, middle, end, buf);
}

void merge (int* begin, int* middle, int* end, int* buf)
{
    int* b = begin;
    int* m = middle;
    while ((b != middle) && (m != end))
    {
        if (*b <= *m)
            *buf = *b++;
        else
            *buf = *m++;
        buf++;
    }
    while (b != middle)
    {
        *buf = *b++;
        *buf++;
    }
    while (m != end)
    {
        *buf = *m++;
        buf++;
    }
    buf = buf - (end - begin);
    b = begin;
    while (b != end)
    {
        *b = *buf++;
        b++;
    }
}
