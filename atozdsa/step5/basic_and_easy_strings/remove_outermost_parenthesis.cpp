#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<int> indices;

  int count = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      count++;
      if (count == 1) indices.push_back(i);
    } else if (s[i] == ')') {
      count--;
      if (count == 0) indices.push_back(i);
    }
  }

  string ans = "";
  for (int i = 0; i < s.length(); i++) {
    if (i == indices[0]) {
      ans += "";
      indices.erase(indices.begin(), indices.begin() + 1);
    } else {
      ans += s[i];
    }
  }
  cout << ans;

  return 0;
}
