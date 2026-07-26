#include <iostream>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  if (k + 2 > n) {
    cout << -1 << '\n';
    return;
  }

  n -= k + 2;
  for (int i = 0; i < k / 2 + 1; i++)
    cout << 0;
  k = k - k / 2;
  for (int i = 0; i < k + 1; i++)
    cout << 1;
  for (int i = 0; i < n; i++)
    cout << (i & 1);

  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
