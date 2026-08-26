#include <array>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  int temp;
  int a0 = 0, b0 = 0;

  cin >> a0;
  for (int i = 1; i < n; i++)
    cin >> temp;

  cin >> b0;
  for (int i = 1; i < m; i++)
    cin >> temp;

  cout << 1 + (b0 + m > a0 + n) << '\n';
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
