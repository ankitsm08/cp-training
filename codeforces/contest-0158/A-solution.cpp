#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int advanced = 0;
  int kth_score = 0;

  for (int i = 1; i <= n; i++) {
    int score;
    cin >> score;

    if (i == k)
      kth_score = score;

    if (score > 0 && (i <= k || score == kth_score))
      advanced++;
  }

  cout << advanced << '\n';

  return 0;
}
