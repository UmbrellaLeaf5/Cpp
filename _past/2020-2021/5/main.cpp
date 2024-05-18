#include <iostream>

using namespace std;

int main()
{

      //It's the first command
    int A;
    int B;
    int C;
    cout << "________________" << endl;
    cout << "Super calculator" << endl;
    cout << "________________" << endl;
    cout << "Input A: ";
    cin >> A;
    cout << "Input B: ";
    cin >> B;
    cout << "Input C: ";
    cin >> C;
    cout << A << " + " << B << " + " << C << " = ";
    cout << A + B + C << endl;
    cout << "________________";
       //It's the second command
    string Name;
    cout << "Input Name: ";
    cin >> Name;
    cout << "Your name is " << Name  ;

      //It's the 3th command

    if(A>5)
    {
        cout << "A > 5 !!!!";
    }
    else
    {
        cout << "A < 5 !!!!";
    }



    cout << "Input A: " ;
    cin >> A;
    cout << "Input B: " ;
    cin >> B;
    int AB = A + B;
    if(AB<0)
    {
        cout <<" Error.";
    }
    else
    {
        cout <<" Your result is: " << AB;
    }

    return 0;

}
