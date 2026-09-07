#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> count(m + 1, 0);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    count[num]++;
  }

  vector<int> suffixSum(m + 2, 0);
  for (int h = m; h > 0; h--)
    suffixSum[h] = suffixSum[h + 1] + count[h];

  int ans = 0;
  for (int hCut = 1; hCut <= m; hCut++)
    ans = max(ans, count[hCut] + suffixSum[hCut + 1] + (2 * hCut <= m ? count[2 * hCut] : 0));

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
