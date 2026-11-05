#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream F ("F:/DIMA/Other/Us.txt");
    int S;
    int i = 0;
    int D = 0;
    int G = 0;
    int H = 0;
    while (F.eof() != true)
    {
        F >> S;
        D = D + S;
        i ++;
    }
    ifstream R ("F:/DIMA/Other/Us.txt");
    while (R.eof() != true)
    {
        R >> G;
        H = H + G;
        i ++;
    }
    if (H > D)
    {
        cout << "The best: User1" << endl;
    }
    else
    {
        cout << "The best: User2" << endl;
    }
    while (F.eof() != true)
    {
        F >> S;

        i ++;
    }
    return 0;
}
