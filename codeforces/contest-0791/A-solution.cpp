#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  cin >> a >> b;

  int years = 0;
  while (a <= b) {
    a *= 3;
    b *= 2;
    years++;
  }

  cout << years << '\n';

  return 0;
}
