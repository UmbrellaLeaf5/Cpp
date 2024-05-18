#include <iostream>

using namespace std;
int A = 0;
int F(int B)
{
    A++;
    cout << "Vsgyfg " << A << endl;
    B++;
    if (B < 10)
    {
        F(B);
    }
    cout << B << endl;
    return B;
}
int main()
{
    F(1);
}
