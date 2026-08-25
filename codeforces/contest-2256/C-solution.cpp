#include <iostream>
#include <string>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  const int n2 = 2 * n;
  int total = 0;
  for (char c : s)
    total += c - '0';

  int red = 0;
  for (int i = 1; i < n2; i += 2) {
    red += s[i] == '1' && s[(i + 1) % n2] == '1';
    red += s[i] == '0' && s[(i - 1) % n2] == '1';
  }

  cout << red << ' ' << total - red << '\n';
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
