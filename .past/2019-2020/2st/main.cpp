#include <iostream>
#include <time.h>
using namespace std;

int main()
{

    cout << "*****" << endl;
    srand(time(NULL));
    //int B = rand () % 5 + 1;
    int B = 5;
    switch (B) {
    case 5: //cout << "VERY YEAH" << endl;
        //break;
    case 4: cout << "YEAH" << endl;
        break;
    case 3: cout << "SO YEAH" << endl;
        break;
    default: cout << "NOT YEAH" << endl;

    }

    return 0;
}
