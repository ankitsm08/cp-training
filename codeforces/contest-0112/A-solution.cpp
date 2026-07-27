#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s1, s2;
  cin >> s1 >> s2;

  const int n = s1.length();

  for (int i = 0; i < n; i++) {
    const char c1 = tolower(s1[i]);
    const char c2 = tolower(s2[i]);
    if (c1 != c2) {
      cout << (2 * (c1 > c2) - 1) << '\n';
      return 0;
    }
  }

  cout << 0 << '\n';
  return 0;
}
