#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> w(n);
  for (int i = 0; i < n; i++)
    cin >> w[i];

  if (n % 2 == 1) {
    cout << "NO\n";
    return;
  }

  int minEven = w[0], maxOdd = w[1];
  for (int i = 2; i < n; i += 2) {
    minEven = min(w[i], minEven);
    maxOdd = max(w[i + 1], maxOdd);
  }

  if (minEven - maxOdd > 1)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
