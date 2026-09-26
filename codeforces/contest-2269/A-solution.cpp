#include <iostream>

using namespace std;

using ull = unsigned long long;

void solve() {
  ull n, k;
  cin >> n >> k;

  cout << (1 << (n - k + 1)) + ((k - 1) << 1) << '\n';
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
