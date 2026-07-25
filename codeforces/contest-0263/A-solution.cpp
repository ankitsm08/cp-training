#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  constexpr int sz = 5;

  int idx = 0, num = 0;
  while (cin >> num && !num)
    idx += num == 0;

  const int m = idx / sz, n = idx % sz;
  cout << (abs(m - sz / 2) + abs(n - sz / 2)) << '\n';

  return 0;
}
