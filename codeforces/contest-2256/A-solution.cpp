#include <algorithm>
#include <iostream>

using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;

  const int mx = max({a, b, c});
  const int mn = min({a, b, c});
  const int md = a + b + c - mx - mn;

  const int ans = (mx > mn + md) ? md : (mx - mn);

  cout << ans << '\n';
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
