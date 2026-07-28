#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x = 0;
  cin >> x;

  cout << (x - 1) / 5 + 1 << '\n';

  return 0;
}
