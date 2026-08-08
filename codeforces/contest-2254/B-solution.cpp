#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int f = 1;
  bool can_remove = false;

  for (int i = 1; i < n - 1; i++) {
    if ((s[i + 1] != s[i] && s[i - 1] != s[i])) {
      can_remove = true;
      if (s[i + 1] == s[i - 1]) {
        f--;
        break;
      }
    }
  }

  for (int i = 1; i < n; i++)
    f += s[i] != s[i - 1];

  f -= can_remove;

  cout << f << '\n';
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
