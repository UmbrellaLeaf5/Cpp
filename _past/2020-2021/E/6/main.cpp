#include <iostream>

using namespace std;

int main()
{
    int a;
    cout << "   3 + 5 * 2" << endl << endl;
    cout << "1. 16" << endl;
    cout << "2. 10" << endl;
    cout << "3. 13" << endl << endl;
    cin >> a;

    if (a == 3)
    {
        cout << "True" << endl << endl;
    }
    if (a != 3)
    {
        cout << "False" << endl << endl;
    }
    cout << "_____________________" << endl;

    cout << "   7 * 8" << endl << endl;
    cout << "1. 64" << endl;
    cout << "2. 56" << endl;
    cout << "3. 32" << endl << endl;
    cin >> a;

    if (a == 2)
    {
        cout << "True" << endl << endl;
    }
    if (a != 2)
    {
        cout << "False" << endl << endl;
    }
    cout << "_____________________" << endl;

    cout << "   128 + 345" << endl << endl;
    cout << "1. 473" << endl;
    cout << "2. 373" << endl;
    cout << "3. 483" << endl << endl;
    cin >> a;

    if (a == 1)
    {
        cout << "True" << endl << endl;
    }
    if (a != 1)
    {
        cout << "False" << endl << endl;
    }
    cout << "_____________________" << endl;

    return 0;
}
