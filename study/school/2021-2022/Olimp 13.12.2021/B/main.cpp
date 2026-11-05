#include <iostream>
using namespace std;

int min(int a, int b, int c = 10000000)
{
    if((a < c) && (a < b))
    {
        return a;
    }
    else if((b < c) && (b < a))
    {
        return b;
    }
    else
    {
        return c;
    }
}
int main()
{
    int n;
    cin >> n;
    int res[n];
    res[0] = 0;
    res[1] = 0;
    res[2] = 1;
    res[3] = 1;
    res[4] = 2;
    res[5] = 3;
    res[6] = 2;
    for(int i = 7; i < n; i++)
    {
        if((i % 3 == 0) && (i % 2 ==0)){
            res[i] = min(res[i / 3], res[i / 2], res[i - 1]) + 1;
            cout << res[i] << endl;
        }
        else if (i % 2 == 0){
            res[i] = min(res[i / 2], res[i - 1]) + 1;
            cout << res[i] << endl;
        }
        else{
            res[i] = res[i - 1] + 1;
            cout << res[i] << endl;
        }
    }
    /*for(int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }*/
    cout << res[n];
    return 0;
}
