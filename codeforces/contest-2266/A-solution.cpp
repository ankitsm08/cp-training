#include <algorithm>
#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;

  int a, b, c;
  cin >> a >> b >> c;

  cout << n - min({a, b, c}) << '\n';
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
