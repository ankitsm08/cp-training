#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  while (k) {
    const int digit = n % 10;
    if (digit > 0) {
      const int reduction = min(k, digit);
      n -= reduction;
      k -= reduction;
    } else {
      n /= 10;
      k--;
    }
  }

  cout << n << '\n';

  return 0;
}
