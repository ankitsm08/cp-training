#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int count = 0;
  char prev = '\0';
  while (n--) {
    char c;
    cin >> c;
    count += (c == prev);
    prev = c;
  }

  cout << count << '\n';

  return 0;
}
