#include <iostream>

using namespace std;

int main()
{
    int numb;
    int RR = 0, RG = 0, RB = 0,
            GG = 0, GB = 0,
            BB = 0;
    cin >> numb;
    for(int j = 0; j < numb; j++)
    {
        string a;
        cin >> a;
        int arr[a.length()];
        int para[2];
        for(unsigned int i = 0; i < a.length(); i++)
        {
            if(a[i] == 'R'){
                arr[i] = 1;}
            else if(a[i] == 'G'){
                arr[i] = 2;}
            else if(a[i] == 'B'){
                arr[i] = 3;}
        }
        for(unsigned int i = 0; i < a.length(); i += 2)
        {
            if(i == 0){
                if(arr[i] == 1 && arr[a.length() - 1] == 1)
                {
                    RR++;
                }
                else if(arr[i] == 2 && arr[a.length() - 1] == 2)
                {
                    GG++;
                }
                else if(arr[i] == 3 && arr[a.length() - 1] == 3)
                {
                    BB++;
                }
                else if((arr[i] == 1 && arr[a.length() - 1] == 2) ||
                        (arr[i] == 2 && arr[a.length() - 1] == 1))
                {
                    RG++;
                }
                else if((arr[i] == 1 && arr[a.length() - 1] == 3) ||
                        (arr[i] == 3 && arr[a.length() - 1] == 1))
                {
                    RB++;
                }
                else if((arr[i] == 2 && arr[a.length() - 1] == 3) ||
                        (arr[i] == 3 && arr[a.length() - 1] == 2))
                {
                    GB++;
                }
            }
            else if(i > 0 && i < a.length() - 2){
                if(arr[i] == 1 && arr[i + 1] == 1)
                {
                    RR++;
                }
                else if(arr[i] == 2 && arr[i + 1] == 2)
                {
                    GG++;
                }
                else if(arr[i] == 3 && arr[i + 1] == 3)
                {
                    BB++;
                }
                else if((arr[i] == 1 && arr[i + 1] == 2) ||
                        (arr[i] == 2 && arr[i + 1] == 1))
                {
                    RG++;
                }
                else if((arr[i] == 1 && arr[i + 1] == 3) ||
                        (arr[i] == 3 && arr[i + 1] == 1))
                {
                    RB++;
                }
                else if((arr[i] == 2 && arr[i + 1] == 3) ||
                        (arr[i] == 3 && arr[i + 1] == 2))
                {
                    GB++;
                }
            }
            int max=RR;
                if (RG>max) max=RG;
                if (RB>max) max=RB;
                if (GG>max) max=GG;
                if (BB>max) max=GG;
                if (GB>max) max=GB;
                cout << max;
        }

    }
    return 0;
}
