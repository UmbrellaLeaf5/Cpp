#include <iostream>
#include <random>
#include <vector>

int main() {
  for (;;) {
    std::vector<unsigned long long> v(100000000000);
    for (auto& x : v)
      x = 3;
    v[5000] = 3;
    std::cout << v[4000] << std::endl;
  }
  for (;;) {
    constexpr int N = 10000;
    int* pv = new int[N];
    for (int i = 0; i < N; ++i)
      pv[i] = 2;
    pv[5000] = 3;
    std::cout << pv[4000] << std::endl;
  }
}