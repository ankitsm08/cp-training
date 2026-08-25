#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  bool all_q_even = s[0] == '?';
  bool all_q_odd = s[1] == '?';

  for (int i = 2; i < n; i++) {
    if (i % 2 == 0) {
      if (s[i - 2] != '?' && s[i - 2] == s[i]) {
        cout << 0 << '\n';
        return;
      }

      all_q_even = all_q_even && (s[i] == '?');
      if (s[i] == '?' && !all_q_even)
        s[i] = '0' + !(s[i - 2] - '0');

    } else {
      if (s[i - 2] != '?' && s[i - 2] == s[i]) {
        cout << 0 << '\n';
        return;
      }

      all_q_odd = all_q_odd && (s[i] == '?');
      if (s[i] == '?' && !all_q_odd)
        s[i] = '0' + !(s[i - 2] - '0');
    }
  }

  cout << (1 << (all_q_even + all_q_odd)) << '\n';
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
