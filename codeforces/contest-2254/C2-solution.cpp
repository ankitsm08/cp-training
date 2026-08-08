#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;

  string s1, s2;
  cin >> s1 >> s2;

  long long ans = 0;
  for (int par = 0; par < 2; par++) {
    int balance = 0;
    for (int i = par; i < n; i += 2) {
      balance += (s1[i] == '1') - (s2[i] == '1');
      ans += abs(balance);
    }
    if (balance != 0) {
      cout << -1 << '\n';
      return;
    }
  }

  cout << ans << '\n';

  return;
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
