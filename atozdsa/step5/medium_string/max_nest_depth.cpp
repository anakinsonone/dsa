#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

int main() {
  string s;
  cin >> s;

  int count = 0, maxCount = 0;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == '(') {
      count += 1;
    } else if (s[i] == ')') {
      maxCount = max(maxCount, count);
      count -= 1;
    }

  cout << maxCount;
  return 0;
}
