#include <iostream>
using namespace std;

int division(int a, int b) {
  if (b != 0)
    return a / b;
  else
    throw runtime_error("Zero division!");
}

int main() {
  int x, y;
  cin >> x >> y;
  cout << division(x, y) << endl;
  system("pause");
  return 0;
}