#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    unsigned long long int a;
    cout << "Введите число: ";
    cin >> a;
    cout << "Вы ввели число: " << a << endl;
    do
    {
        if (a % 2 == 0)
        {
           a =  a / 2;
            cout << "чётное,/2: " << a << endl;
        }
        else
        {
            a = a * 3 + 1;
            cout <<  "нечётное,3х+1: " << a << endl;
        }
     } while (a != 1);
     system("pause");
        return 0;
}
