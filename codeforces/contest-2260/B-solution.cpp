#include <iostream>

using namespace std;

using ull = unsigned long long;

void solve() {
  ull x, y, k;
  cin >> x >> y >> k;

  ull total = 0, i = 0;
  for (; i < k && (y + i) >= 2 * (x + i); i++)
    total += (y + i) % (x + i);

  k -= i;

  cout << total + k * ((y + i) % (x + i)) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
