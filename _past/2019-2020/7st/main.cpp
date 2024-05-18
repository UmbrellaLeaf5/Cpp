#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream F ("F:/DIMA/Other/Qafg.txt");
    ofstream Fout("F:/DIMA/Other/out.txt");
    char Q[500];
    int S;
    int i = 0;
    while (F.eof() != true)
    {
        F >> S;
        if (S % 2 == 0)
        {
            cout << S << " ";
            Fout << S << " ";

        }
        i ++;
    }
    Fout.close();
    F.close();
    return 0;
}
