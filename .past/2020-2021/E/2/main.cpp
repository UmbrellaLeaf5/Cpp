#include <iostream>

using namespace std;

int main()
{
    int s;
    cin >> s;
    if (s != 12)
    {
        cout << s / 12 + 1;
    }
    else
    {
        cout << "1";
    }
    return 0;
}
