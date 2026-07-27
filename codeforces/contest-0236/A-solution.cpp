#include <bitset>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  bitset<26> chars;

  char c = '\0';
  while (cin.get(c) && c != '\n')
    chars.set(c - 'a');

  if (chars.count() % 2 == 1)
    cout << "IGNORE HIM!\n";
  else
    cout << "CHAT WITH HER!\n";

  return 0;
}
