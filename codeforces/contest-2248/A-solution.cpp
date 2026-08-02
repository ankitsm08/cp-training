#include <iostream>

using namespace std;

void solve() {
  string s;
  cin >> s;

  bool zero = false, one = false;
  for (const char c : s) {
    if (c == '0') {
      if (zero)
        cout << '0';
      zero = true;
    } else {
      if (one)
        cout << '1';
      one = true;
    }
  }

  cout << '\n';
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
