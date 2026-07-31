#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;

  if (s1.length() != s2.length()) {
    cout << "NO\n";
    return 0;
  }

  const int n = static_cast<int>(s1.length());
  bool same = true;
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[n - i - 1]) {
      same = false;
      break;
    }
  }

  cout << (same ? "YES" : "NO") << '\n';

  return 0;
}
