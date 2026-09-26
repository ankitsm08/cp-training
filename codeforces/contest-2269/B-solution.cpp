#include <array>
#include <iostream>

using namespace std;

using ll = long long;

inline int sum_of_sq_digit(int n) {
  int sum = 0;
  for (int x = n; x > 0; x /= 10)
    sum += (x % 10) * (x % 10);
  return sum;
}

int canonical(int x) {
  for (int i = 0; i < 250; i++)
    x = sum_of_sq_digit(x);

  return x;
}

void solve() {
  int n;
  cin >> n;

  array<int, 730> freq{};

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    freq[canonical(x)]++;
  }

  ll ans = 0;
  for (int x : freq)
    ans += 1LL * x * (x - 1) / 2;

  cout << ans << '\n';
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
