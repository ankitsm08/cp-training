#include <iostream>
#include <numeric>

using namespace std;

void solve() {
  int n;
  cin >> n;

  int a;
  cin >> a;

  int b = a;
  for (int i = 1; i < n; i++)
    cin >> b;

  cout << gcd(a, b) << '\n';
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
