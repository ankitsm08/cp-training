#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  int total = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    total += a[i];
  }

  ranges::sort(a);

  int health = 0, most = 0, count = 0;
  for (int i = 0, j = 0; i < n; i = j) {
    while (j < n && a[i] == a[j])
      j++;

    if (j - i > count) {
      most = a[i];
      count = j - i;
    }
  }

  health = total - max(0, count - (n - count) - 2) * most;

  cout << health << '\n';
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
