#include <iostream>
#include <string.h>

using namespace std;

void Decor()
{
    cout << "==================" << endl;
    cout << "====DECORATION====" << endl;
    cout << "==================" << endl;
}

int main()
{
    char Ch[] = "abcde";
    cout << strlen(Ch) << endl;
    Decor();
    for (int i = 0; i < strlen(Ch); i ++)
    {
        cout << Ch[i] << endl;
    }

    Decor();

    strcpy_s(Ch, "ab");
    cout << Ch << endl;

    Decor();

    char Ch2[] = "222";
    strcat_s(Ch2, Ch);
    cout << Ch2 << endl;

    Decor();

    char FIO[50];
    char F[] = "Ivanov";
    char N[] = "Ivan";
    strcpy_s(FIO, F);
    strcat_s(FIO, " ");
    strncat(FIO, N,1);
    strcat_s(FIO, ".");
    cout << FIO << endl;

    Decor();

    return 0;
}
