#include <iostream>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int changes = 0;
  for (int i = 0; i < n - 1; i++)
    changes += s[i] != s[i + 1];

  cout << 1 + (changes == 1) << '\n';
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
