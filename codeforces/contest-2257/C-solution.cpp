#include <array>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_N = 2e5 + 1;

array<int, MAX_N> p;
array<int, MAX_N> a;

void solve() {
  int n;
  cin >> n;

  p[1] = 1;
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
    p[i] = p[p[i]] + 1;
  }

  int m;
  cin >> m;

  for (int i = 1; i <= m; i++)
    cin >> a[i];

  int rootmost = a[1];
  for (int i = 1; i <= m; i++) {
    if (p[a[i]] < p[rootmost])
      rootmost = a[i];
  }

  cout << m - 1;
  for (int i = 1; i <= m; i++) {
    if (a[i] != rootmost)
      cout << ' ' << a[i];
  }
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
