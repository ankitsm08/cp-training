#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, a;
  cin >> n >> m >> a;

  cout << 1LL * ((n + a - 1) / a) * ((m + a - 1) / a) << endl;

  return 0;
}
