#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char c;
  cin.get(c);
  c = (c >= 'a' && c <= 'z') ? c + 'A' - 'a' : c;
  cout << c;

  while (cin.get(c) && c != '\n')
    cout << c;

  return 0;
}
