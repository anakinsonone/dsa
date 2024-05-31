#include <bits/stdc++.h>

#include <string>
using namespace std;

string printArr(vector<char>& arr) {
  string ans;
  for (int i = 0; i < arr.size(); i++) {
    ans = ans + ' ' + arr[i];
  }
  return ans;
}
int main() {
  string s, t;
  cin >> s >> t;

  int sArr[256] = {0}, tArr[256] = {0}, n = s.size();
  for (int i = 0; i < s.size(); i++) {
    if (sArr[s[i]] != tArr[t[i]]) {
      cout << false;
      return 0;
    }
    sArr[s[i]] = i + 1;
    tArr[t[i]] = i + 1;
  }
  cout << true;

  return 0;
}
