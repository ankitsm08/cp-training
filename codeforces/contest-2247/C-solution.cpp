#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);

  for (auto &x : a)
    cin >> x;

  for (auto &x : b)
    cin >> x;

  if (a == b) {
    cout << 0 << '\n';
    return;
  }

  if (ranges::fold_left(a, 0, plus{}) == 0 || ranges::fold_left(b, 0, plus{}) == n) {
    cout << -1 << '\n';
    return;
  }

  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += a[i] != b[i] && a[i] != 0;

  if (sum % 2 == 1)
    cout << 1 << '\n';
  else
    cout << 2 << '\n';
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
