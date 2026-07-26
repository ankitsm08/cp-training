#include <array>
#include <iostream>

using namespace std;

struct LRUV {
  int l, r, u, v;
};
array<LRUV, 5001> limits{};

bool check(int m, int n) {
  int j = 1;
  for (int i = 1; i <= n; i++) {
    bool inLeft = (j >= limits[i].l && j <= limits[i].r);
    bool inRight = (m - j + 1 >= limits[i].u && m - j + 1 <= limits[i].v);

    if (!inLeft && !inRight) {
      j++;
      if (j > m)
        return true;
    }
  }
  return false;
}

void solve() {
  int n;
  cin >> n;

  for (int i = 1; i < n + 1; i++)
    cin >> limits[i].l >> limits[i].r >> limits[i].u >> limits[i].v;

  if (n <= 1) {
    cout << 0 << '\n';
    return;
  }

  int max_m = 0;
  for (int i = n; i > 0; i--) {
    if (check(i, n)) {
      max_m = i;
      break;
    }
  }

  cout << max_m << '\n';
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
