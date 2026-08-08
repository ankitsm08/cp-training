#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<pair<ll, int>> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i].first;
    b[i].second = i;
  }

  ranges::sort(b, [](const auto &a, const auto &b) { return a.first < b.first; });

  if (b[0].first != 0) {
    cout << -1 << '\n';
    return;
  }

  ll prev_b_val = 0, prev_a_val = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    ll b_val = b[i].first;

    count += prev_b_val == b_val;

    if (prev_b_val != b_val) {
      ll gap = b_val - prev_b_val;
      ll a_val = gap / count;
      if (gap % count != 0 || prev_a_val >= a_val) {
        cout << -1 << '\n';
        return;
      }

      for (int j = 0; j < count; j++)
        b[i - j - 1].first = a_val;

      count = 1;
      prev_b_val = b_val;
      prev_a_val = a_val;
    }
  }

  for (int j = 0; j < count; j++)
    b[n - j - 1].first = prev_a_val + 1;

  ranges::sort(b, [](const auto &a, const auto &b) { return a.second < b.second; });

  for (int i = 0; i < n - 1; i++)
    cout << b[i].first << ' ';
  cout << b.back().first << '\n';
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
