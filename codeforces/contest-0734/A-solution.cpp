#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n = 0;
  cin >> n;

  int A = 0;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    A += c == 'A';
  }

  if (A > n - A)
    cout << "Anton";
  else if (A < n - A)
    cout << "Danik";
  else
    cout << "Friendship";

  cout << '\n';
  return 0;
}
