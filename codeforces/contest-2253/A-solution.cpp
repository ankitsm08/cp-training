#include <cmath>
#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;
  n++;

  const int sqrt_n = sqrt(n);
  for (int i = 2; i <= sqrt_n; i++) {
    if (n % i == 0) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
