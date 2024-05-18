#include <iostream>

using namespace std;

int main()
{
    int numb, allm = 0;
    cin >> numb;
    int arr[numb];
    for(int i = 0; i < numb; i++)
    {
        cin >> arr[i];
    }
    int m_daystart[numb];
    int m_dayend[numb];
    for(int i = 0; i < numb; i++)
    {
        cin >> m_daystart[i] >> m_dayend[i];
    }
    for(int i = 0; i < numb; i++)
    {
        if(arr[i] > 0)
        {
            if(m_dayend[i] - m_daystart[i] > 0){
            allm += m_dayend[i] - m_daystart[i];}
        }
    }
    cout << allm;
}
