#include<iostream>

using namespace std;

int main ()

{
    int x;
    int y;
    cin >> x;
    cin >> y;
    if (y > 0)
    {
        y = y - x;
        x = x + y / 5;
    }
    else
    {
        cout << x;
    }
}
