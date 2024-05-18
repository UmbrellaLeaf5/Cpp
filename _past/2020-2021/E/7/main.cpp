#include <iostream>

using namespace std;

int main()
{
  int a = 0, b1, b, i = 0;
  long long m = 1;
  cin >> b1;
  while (m != 0)
  {
    cin >> m;
    if (i == 0)
    {
      if (m > b1)
      {
        b = m;
      }
    }
    if (m > b)
    {
      b = m;
      a = i;
    }
    b1 = m;
    i++;
  }
  cout << b;
}
