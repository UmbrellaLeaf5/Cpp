#include "my_sort.h"
#include "str_oper.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

void print (const vector<int> v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

bool operator== (const vector<int>& v1, const vector<int>& v2)
{
    if (v1.size() != v2.size())
        return false;
    else
    {
        for (auto i = 0; i < v1.size(); i++)
        {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    }
}

int main ()
{
    // код, вызывающий неопределенное поведение:
    // vector<int> v(100);
    // cout << v.size() << endl;
    // vector<int>* pv = new vector<int>(100);
    // vector<int>* pv2 = static_cast<vector<int>*>(malloc(sizeof(vector<int>)));
    // cout << pv2->size() << endl;

    // int *p = nullptr, *q = nullptr;
    // int a = 1;
    // p = &a;
    // *p = 2;
    // int& r = a;  // понимается как второе имя, память "не выделяется", нельзя перепривязать
    //              // у ссылки нет адреса
    // r = 3;
    // p = &r;

    vector<int> src{1, 3, 4, 5, 7, 1, 4, 5, 6, 8, 3, 2};
    vector<int> v1{src};
    sort(v1.begin(), v1.end());
    print(src);
    print(v1);
    vector<int> v2{src};
    merge_sort(&v2[0], &v2[0] + v2.size());
    print(v2);
    cout << (v2 == v1) << endl;
    cout << findx("Hello world! How are you?", "world");
    return 0;
}
