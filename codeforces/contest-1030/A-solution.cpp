#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  bool result = false;
  while (n--) {
    int num;
    cin >> num;
    result = result || num == 1;
  }

  cout << (result ? "HARD" : "EASY") << '\n';

  return 0;
}
