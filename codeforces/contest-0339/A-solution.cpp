#include <array>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  array<int, 3> freq{};
  for (char c : s)
    if (c != '+')
      freq[c - '1']++;

  bool first = true;
  for (int i = 0; i < 3; i++) {
    while (freq[i]--) {
      if (!first)
        cout << '+';
      cout << i + 1;
      first = false;
    }
  }

  return 0;
}
