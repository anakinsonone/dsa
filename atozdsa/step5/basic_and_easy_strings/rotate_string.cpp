#include <bits/stdc++.h>
using namespace std;

void rotateString(string &s, int shift) {
  reverse(s.begin(), s.begin() + shift);
  reverse(s.begin() + shift, s.end());
  reverse(s.begin(), s.end());
}

int main() {
  string s, goal;
  cin >> s >> goal;

  for (int i = 0; i < s.length(); i++) {
    rotateString(s, 1);
    if (s == goal) {
      cout << true;
      return 0;
    }
  }
  cout << false;

  return 0;
}
