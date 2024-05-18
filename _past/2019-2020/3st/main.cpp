#include <iostream>
#define OTL 5
#define HOR 4
#define UD 3
using namespace std;

int main()
{
    string Otv;

    cout << "2 + 2 =" << endl;
    cout << "OmBem: ";
    cin >> Otv;
    int Res = 0;
    if (Otv == "4")
    {
        Res ++;
        cout << "+" << endl;
    }
    else
    {
        cout << "-" << endl;
    }
    cout << "2 + 2 =" << endl;
    cout << "OmBem: ";
    cin >> Otv;

    if (Otv == "4")
    {
        Res ++;
        cout << "+" << endl;
    }
    else
    {
        cout << "-" << endl;
    }
    cout << "2 + 2 =" << endl;
    cout << "OmBem: ";
    cin >> Otv;

    if (Otv == "4")
    {
        Res ++;
        cout << "+" << endl;
    }
    else
    {
        cout << "-" << endl;
    }
    cout << "2 + 2 =" << endl;
    cout << "OmBem: ";
    cin >> Otv;

    if (Otv == "4")
    {
        Res ++;
        cout << "+" << endl;
    }
    else
    {
        cout << "-" << endl;
    }
    cout << "2 + 2 =" << endl;
    cout << "OmBem: ";
    cin >> Otv;

    if (Otv == "4")
    {
        Res ++;
        cout << "+" << endl;
    }
    else
    {
        cout << "-" << endl;
    }
    switch (Res)
    {
    case OTL: cout << "YEAH";
        break;
    case HOR: cout << "SO YEAH";
        break;
    case UD: cout << "NOT YEAH";
        break;
    default: cout << "GO AWAY";
    }
    return 0;
}
