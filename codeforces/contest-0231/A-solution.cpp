#include <bits/stdc++.h>

using namespace std;

int main() {
  int t = 1;
  cin >> t;

  int ans = 0;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    ans += a + b + c >= 2;
  }

  cout << ans << '\n';
  return 0;
}
