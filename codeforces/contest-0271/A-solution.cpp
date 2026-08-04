#include <array>
#include <iostream>

using namespace std;

bool distinct(int num) {
  array<int, 10> seen{};

  while (num) {
    if (seen[num % 10])
      return false;
    seen[num % 10] = true;
    num /= 10;
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int y;
  cin >> y;

  while (!distinct(++y))
    ;

  cout << y << '\n';

  return 0;
}
