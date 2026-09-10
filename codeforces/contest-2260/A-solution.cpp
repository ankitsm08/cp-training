#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;

  int first;
  cin >> first;

  int sum = !first;
  int last;
  for (int i = 1; i < n; i++) {
    cin >> last;
    sum += !last;
  }

  if (sum < 2) {
    cout << "-1\n";
    return;
  }

  cout << 2 - !first - !last << '\n';
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
