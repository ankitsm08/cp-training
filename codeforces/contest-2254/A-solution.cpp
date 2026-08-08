#include <iostream>

using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;

  int ans = min({abs(a - b), abs(b - c), abs(c - a)});

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
