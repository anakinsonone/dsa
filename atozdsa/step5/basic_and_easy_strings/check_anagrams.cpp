#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  if (s == t) {
    cout << true;
    return 0;
  }
  cout << false;
  return 0;
}
