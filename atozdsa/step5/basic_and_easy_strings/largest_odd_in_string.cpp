#include <bits/stdc++.h>

#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  string odd = "";
  for (int i = s.length() - 1; i >= 0; i--) {
    int num = stoi(string(1, s[i]));
    if (num % 2 == 1) {
      odd = s.substr(0, i + 1);
      break;
    }
  }

  cout << odd;
  return 0;
}
