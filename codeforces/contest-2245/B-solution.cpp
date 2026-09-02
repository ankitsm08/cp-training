#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

void solve() {
  int n, c;
  cin >> n >> c;

  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
    x -= c;
  }

  ranges::sort(a);

  for (int i = 0; i < n / 2; i++)
    a[i] = max(a[i], 0);

  cout << ranges::fold_left(a, 0LL, plus{}) << '\n';
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
