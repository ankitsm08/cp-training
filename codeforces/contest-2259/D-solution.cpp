#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  int zeros = 0;
  vector<pair<int, char>> a(n, {0, 'A'});
  for (auto &[x, c] : a) {
    cin >> x;
    zeros += x == 0;
  }

  if (zeros == 1) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";

  if (zeros >= 2) {
    auto it = ranges::find(a, pair{0, 'A'});
    (*it).second = 'B';
    it = find(it + 1, a.end(), pair{0, 'A'});
    (*it).second = 'C';
  }

  if (zeros >= 3) {
    for (auto &[x, c] : a) {
      if (x == 1) {
        c = 'B';
      } else if (x == 2) {
        c = 'C';
      }
    }
  }

  for (auto &[x, c] : a)
    cout << c;
  cout << '\n';
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
