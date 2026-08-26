#include <array>
#include <iostream>

using namespace std;

constexpr int MAX_N = 2 * 1e5;
array<int, MAX_N> a;

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  int runs = 1;

  for (int i = 1; i < n; i++)
    runs += a[i] != a[i - 1];

  if (n <= 2) {
    cout << runs << '\n';
    return;
  } else if (n == 3) {
    cout << (runs == 1 ? 1 : 3) << '\n';
    return;
  }

  for (int i = 0; i + 3 < n; i++) {
    if (a[i] == a[i + 1] && a[i + 1] != a[i + 2] && a[i + 2] == a[i + 3] && a[i] != a[i + 3]) {
      cout << runs + 2 << '\n';
      return;
    }
  }

  if ((a[0] != a[1] && a[1] == a[2]) || (a[n - 1] != a[n - 2] && a[n - 2] == a[n - 3])) {
    cout << runs + 1 << '\n';
    return;
  }

  for (int i = 0; i + 3 < n; i++) {
    if ((a[i] == a[i + 1] && a[i + 1] != a[i + 2] && a[i + 2] != a[i + 3] && a[i] != a[i + 3])
        || (a[i] != a[i + 1] && a[i + 1] != a[i + 2] && a[i + 2] == a[i + 3] && a[i] != a[i + 3])) {
      cout << runs + 1 << '\n';
      return;
    }
  }

  cout << runs << '\n';
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
