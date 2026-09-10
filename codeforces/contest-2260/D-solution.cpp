#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<pair<char, int>> runs;

  char prev = '\0';
  for (auto ch : s) {
    if (prev != ch)
      runs.emplace_back(ch, 1);
    else
      runs.back().second++;

    prev = ch;
  }

  int mx = 1;
  int sum = 0;

  for (const auto &[ch, len] : runs) {
    if (ch == '0' && len >= 2) {
      cout << "-1\n";
      return;
    }

    if (len >= 3) {
      const int new_sum = 2 * (ch == '+') - 1;
      mx = max(mx, abs(sum - new_sum));
      sum = new_sum;
    }
  }

  cout << mx << '\n';
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
