#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

using ll = long long;

struct Interval {
  int l = -1;
  int r;
  ll w;
};

void solve() {
  int n;
  cin >> n;
  const int N = 2 * n;

  vector<Interval> intervals(n);
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    auto &[l, r, w] = intervals[--num];
    if (l == -1)
      l = i;
    else {
      r = i;
      const int len = r - l + 1;
      w = static_cast<ll>(len) * (len - 1);
    }
  }

  ranges::sort(intervals, [](const auto &a, const auto &b) { return a.r < b.r; });

  vector<ll> dp(N + 1, 0);
  int i = 0;
  for (int j = 1; j <= N; j++) {
    dp[j] = dp[j - 1];
    while (i < n && intervals[i].r == j - 1) {
      auto &[l, r, w] = intervals[i++];
      dp[j] = max(dp[j], dp[l] + w);
    }
  }

  cout << N + dp[N] << '\n';
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
