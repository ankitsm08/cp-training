#include <iostream>

using namespace std;

int main() {
  int t = 1;
  cin >> t;

  int x = 0;
  while (t--) {
    char c1, c2, c3;
    cin >> c1 >> c2 >> c3;

    x += '+' - c2 + 1;
  }

  cout << x << '\n';

  return 0;
}
