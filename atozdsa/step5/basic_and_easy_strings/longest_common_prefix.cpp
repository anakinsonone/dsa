#include <bits/stdc++.h>

#include <climits>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> sArr(n, "");
  for (int i = 0; i < n; i++) {
    cin >> sArr[i];
  }

  sort(sArr.begin(), sArr.end());
  string first = sArr[0];
  string last = sArr[n - 1];

  string ans = "-1";
  for (int i = 0; i < first.length(); i++) {
    if (first[i] == last[i]) {
      ans += first[i];
    } else
      break;
  }
  cout << ans;

  return 0;
}
