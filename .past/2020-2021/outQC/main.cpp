#include <iostream>

using namespace std;

class Array
{
public:
    int *A = new int[4];
    int *B;
    int max = 4;
    int len = 0;
    bool first = true;
    void append(int N)
    {
        if(len == max)
        {
            max += 4;
            {
                if (first)
                {
                    B = new int[max];
                    for(int i = 0; i < len; i ++)
                    {
                        B[i] = A[i];
                    }
                    delete[] A;
                    first = false;
                }
            }
            if(first)
            {
                A[len] = N;
            }
            else
            {
                B[len] = N;
            }
        }
        A[len] = N;
        len++;
    }
    void insert(int in, int N)
    {
        if(first){
        for(int i = len; i > in; i --)
        {
            A[i] = A[i - 1];
        }
        A[in] = N;
        len ++;
        }
        else
        {
            for(int i = len; i > in; i --)
            {
                B[i] = B[i - 1];
            }
            B[in] = N;
            len ++;
        }
    }
    int at(int index)
    {
        return A[index];
    }
};

int main()
{
    Array Arr;
    Arr.append(10);
    Arr.append(20);
    Arr.insert(1, 15);
    Arr.append(50);
    for(int i = 0; i < Arr.len; i++)
    {
        cout << Arr.at(i) << ", ";
    }
    return 0;
}
