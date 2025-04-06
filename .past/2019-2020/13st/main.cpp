#include <iostream>
using namespace std;
int M[6][10] =
{
    {0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 1, 1, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
};
void show()
{
    int kol = 0;
    system("cls");
   for (int y = 0; y < 6; y ++)
   {
       for(int x = 0; x < 10; x ++)
       {
           if (M[y][x] == 1)
           {
               cout << "* ";
           }
           else if(M[y][x] == 0)
           {
               cout << "* ";
           }
           else if(M[y][x] == 2)
           {
               if (M[y][x+1] == 1)
               {
                   kol++;
               }
               if (M[y+1][x+1] == 1)
               {
                   kol++;
               }
               if (M[y+1][x] == 1)
               {
                   kol++;
               }
               if (M[y-1][x] == 1)
               {
                   kol++;
               }
               if (M[y-1][x-1] == 1)
               {
                   kol++;
               }
               if (M[y][x-1] == 1)
               {
                   kol++;
               }
               cout << kol << " ";
               kol = 0;
           }
           else if(M[y][x] == 3)
           {
               cout << "- ";
           }

       }
       cout << endl;
   }
}
void change(int x, int y, int m, int err)
{
    if ( err == 0)
    {
    cout << "Enter mode: ";
    cin >> m;
    if ( m == 1 )
    {
        m = 2;
    }
    else if ( m == 2 )
    {
        m = 3;
    }
    cout << "Enter X: ";
    cin >> x;
    x--;
    cout << "Enter Y: ";
    cin >> y;
    y--;
    if (M[y][x] == 0)
    {
    M[y][x] = m;
    }
    else if(m == 3)
    {
        M[y][x] = 3;
    }
    else
    {
        cout << "No";
        err ++;
    }
    }
    else
    {
        cout << "You lose!";
    }

}
int main()
{
    while (true)
    {
        show();
        change(0, 0, 0, 0);
    }
    return 0;
}
