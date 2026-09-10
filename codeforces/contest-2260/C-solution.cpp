#include <bit>
#include <iostream>

using namespace std;

using ull = unsigned long long;

void solve() {
  ull x, y;
  cin >> x >> y;

  const ull sum = x + y;

  bool dec = false;
  const ull original_x = x;
  for (int i = bit_width(x); i-- > 0;) {
    const bool x_bit = (x >> i) & 1;
    const bool sum_bit = (sum >> i) & 1;

    if (x_bit && !sum_bit) {
      x ^= 1ull << i;
      dec = true;
    } else if (!x_bit && sum_bit && dec) {
      x ^= 1ull << i;
    }
  }

  const ull num_operations = original_x - x;
  y += num_operations;

  cout << (x ^ y) << ' ' << num_operations << '\n';
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
