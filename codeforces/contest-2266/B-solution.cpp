#include <cstdlib>
#include <iostream>

using namespace std;

using ll = long long;

void solve() {
  ll a, b, c;
  cin >> a >> b >> c;

  cout << max(a - b + c, b - a) << '\n';
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
