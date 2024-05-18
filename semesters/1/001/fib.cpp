#include <iostream>
using namespace std;

unsigned long FibRec(unsigned long i) {
  if (i < 1)
    return 0;
  if (i == 1)
    return 1;
  return FibRec(i - 1) + FibRec(i - 2);
}

unsigned long FibCir(unsigned long start) {
  unsigned long need = 1;
  unsigned long fir = 0;
  unsigned long sec;
  for (int i = 1; i < start; i++) {
    sec = need;
    need += fir;
    fir = sec;
  }
  return (need * (start != 0));
}

int main() {
  unsigned long start = 0;
  cin >> start;
  cout << FibCir(start) << endl << FibRec(start) << endl;
  return 0;
}