#include <iostream>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  int count = 0;

  for (int i = 0; i < n / k; i++) {
    bool all_owned = true;
    for (int j = 0; j < k; j++) {
      char c;
      cin >> c;
      all_owned &= c == '1';
    }
    count += all_owned;
  }

  cout << count << '\n';
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
