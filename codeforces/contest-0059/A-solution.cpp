#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  const int n = static_cast<int>(s.length());
  int lower = 0;
  for (char &c : s) {
    if (c >= 'a' && c <= 'z')
      lower++;
    else
      c = c - 'A' + 'a';
  }

  char base = lower >= n - lower ? 'a' : 'A';

  for (char &c : s)
    c = base + c - 'a';

  cout << s << '\n';

  return 0;
}
