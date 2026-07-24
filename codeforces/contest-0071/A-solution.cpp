#include <iostream>
#include <string>

using namespace std;

void solve() {
  string s;
  cin >> s;

  if (s.length() > 10)
    cout << s.front() << s.length() - 2 << s.back() << '\n';
  else
    cout << s << '\n';
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
