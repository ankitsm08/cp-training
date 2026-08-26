#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  array<bool, 26> freq{};

  string s;
  while (n--) {
    cin >> s;
    freq[s[0] - 'a'] = true;
  }

  bool possible = true;
  while (m--) {
    cin >> s;
    possible = possible && ranges::all_of(s, [&](char ch) { return freq[ch - 'A']; });
  }

  cout << (possible ? "YES" : "NO") << '\n';
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
