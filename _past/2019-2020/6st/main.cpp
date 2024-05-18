#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout << "TTpuBem Mup!" << endl;
    ofstream F ("F:/DIMA/Other/Qaq.txt");
    F << "TTpuBem Tbl!" << endl;
    F << " TTpuBem !" << endl;
    F << "TTpuBem!" << endl;
    ifstream Fin ("F:/DIMA/Other/Qaq.txt");
    char buf[100];
    string S;
    Fin >> buf;
    cout << buf;

    cout << S << endl;
    Fin.getline(buf, 100);
    cout << buf << endl;
    while (Fin.eof() == false)
    {
        getline(Fin, S);
        cout << S << endl;

    }
    int Arr[5];
    ifstream Q("F:/DIMA/Other/Qaqtxt");
    int i = 0;
    while (Q.eof() != true)
    {
        Q >> Arr[i];
        i ++;
    }

    return 0;
}
