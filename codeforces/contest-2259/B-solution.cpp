#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  int one = 0, zero = 0, two = 0;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    one += (x & 1) == 1;
    zero += (x & 3) == 0;
    two += (x & 3) == 2;
  }

  cout << max({one, zero, two}) << '\n';
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
