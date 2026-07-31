#include <iostream>

using namespace std;

using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  int count = 0;
  for (ll x = n; x > 0; x /= 10) {
    const int digit = x % 10;
    count += (digit == 7 || digit == 4);
  }

  if (count == 4 || count == 7) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}
