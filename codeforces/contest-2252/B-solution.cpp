#include <algorithm>
#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;

  char ch;
  cin >> ch;

  int zeros = ch == '0', ones = ch == '1';
  int runs0 = zeros, runs1 = ones;

  for (int i = 1; i < n; i++) {
    const char prev = ch;
    cin >> ch;

    zeros += ch == '0';
    ones += ch == '1';
    runs0 += ch != prev && ch == '0';
    runs1 += ch != prev && ch == '1';
  }

  const int diff = zeros - ones;
  if (diff > 2 || diff < -2) {
    cout << -1 << '\n';
    return;
  }

  // diophantine inequality
  int best = -1;
  for (const int kept : {diff - 1, diff, diff + 1}) {
    if (kept < -1 || kept > 1)
      continue;

    const int low = max(0, -kept);
    const int high = min(runs1, runs0 - kept);
    if (low <= high)
      best = max(best, 2 * high + kept);
  }

  cout << n - best << '\n';
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
