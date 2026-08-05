#include <iostream>

using namespace std;

using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  ll ans = 3LL * (3 * n - 1) * (1LL << (2 * n - 6));
  cout << ans << '\n';

  return 0;
}
