#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, h;
  cin >> n >> h;

  int width = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    width += 1 + (a > h);
  }

  cout << width << '\n';

  return 0;
}
