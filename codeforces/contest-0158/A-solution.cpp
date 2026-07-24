#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int advanced = 0;
  int score = 0;
  while (k--) {
    n--;
    cin >> score;
    if (score > 0)
      advanced++;
    else
      break;
  }

  if (score > 0) {
    int last_score = score;
    while (n--) {
      cin >> score;
      if (score == last_score)
        advanced++;
      else
        break;
    }
  }

  cout << advanced << '\n';

  return 0;
}
