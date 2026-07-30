#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k, n, w;
  cin >> k >> n >> w;

  const int cost = k * w * (w + 1) / 2;
  cout << max(0, cost - n) << '\n';

  return 0;
}
