#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  unordered_map<char, int> mpp;
  for (int i = 0; i < s.length(); i++)
    mpp[s[i]]++;
  cout << mpp.size() << '\n';

  vector<string> ansArr(s.length() + 1, "");
  for (auto &it : mpp) {
    char c = it.first;
    int n = it.second;
    ansArr[n].append(n, c);
  }

  string ans;
  for (int i = s.length(); i > 0; i--) {
    if (!ansArr[i].empty()) {
      ans.append(ansArr[i]);
    }
  }
  cout << ans;

  return 0;
}
