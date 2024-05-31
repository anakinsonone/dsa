#include <bits/stdc++.h>
using namespace std;

enum romanNumerals {
  I = 1,
  V = 5,
  X = 10,
  L = 50,
  C = 100,
  D = 500,
  M = 1000,
};

int charToRomanNumeral(char c) {
  switch (c) {
    case 'I':
      return I;
    case 'V':
      return V;
    case 'X':
      return X;
    case 'L':
      return L;
    case 'C':
      return C;
    case 'D':
      return D;
    case 'M':
      return M;
    default:
      return 0;
  }
}

int main() {
  string s;
  cin >> s;

  int num = 0;
  for (int i = 0; i < s.length(); i++) {
    int currNum = charToRomanNumeral(s[i]);
    num = num + currNum;
    if (i > 0) {
      int prevNum = charToRomanNumeral(s[i - 1]);
      if (prevNum < currNum) {
        num = num - prevNum - currNum;
        num = num + (currNum - prevNum);
      };
    }
  }
  cout << num;

  return 0;
}
