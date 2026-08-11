#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n = 1;
  cin >> n;

  int max_passengers = 0;
  int passengers = 0;
  while (n--) {
    int a, b;
    cin >> a >> b;

    passengers += b - a;
    max_passengers = max(max_passengers, passengers);
  }

  cout << max_passengers << '\n';

  return 0;
}
