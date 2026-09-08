#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &x : a)
    cin >> x;

  for (int i = 0; i < n; i++) {
    if (a[i] == -1)
      a[i] = 1;
    if (a[i] == 1)
      break;
  }

  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == -1)
      a[i] = 1;
    if (a[i] == 1)
      break;
  }

  ranges::replace(a, -1, 0);

  for (auto x : a)
    cout << x << ' ';

  cout << '\n';
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
