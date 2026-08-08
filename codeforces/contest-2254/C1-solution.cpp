#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;

  string s1, s2;
  cin >> s1 >> s2;

  int odd = 0, even = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      even += (s1[i] == '1') - (s2[i] == '1');
    else
      odd += (s1[i] == '1') - (s2[i] == '1');
  }

  if (even == 0 && odd == 0)
    cout << "YES\n";
  else
    cout << "NO\n";
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
