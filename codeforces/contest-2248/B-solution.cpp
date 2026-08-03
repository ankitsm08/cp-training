#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  if (n < m * 2) {
    cout << "NO\n";
    return;
  }

  ranges::sort(a);
  ranges::sort(b);

  for (int k = 0; k < m; k++) {
    if (a[k] > b[k] || a[n - m + k] < b[k]) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
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
