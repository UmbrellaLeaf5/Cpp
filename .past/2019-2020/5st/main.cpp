#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string FIO;
    string F;
    string N;
    string O;
    cout << "Fam.: ";
    cin >> F;
    cout << "Name: ";
    cin >> N;
    cout << "Ot.: ";
    cin >> O;
    cout << F << ". "
         << N[0] << ". "
         << O[0] << ". "
         << endl;
    cout << FIO << endl;
    return 0;
}
