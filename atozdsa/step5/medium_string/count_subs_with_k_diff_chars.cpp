#include <bits/stdc++.h>

#include <cstring>
using namespace std;

int main() {
  int k;
  string s;
  cin >> s >> k;

  int arr[26];
  int count = 0;
  for (int i = 0; i < s.length(); i++) {
    int distinct = 0;
    memset(arr, 0, sizeof(arr));
    for (int j = i; j < s.length(); j++) {
      if (arr[s[j] - 'a'] == 0) {
        distinct++;
      }
      arr[arr[s[j] - 'a']]++;
      if (distinct == k) count++;
      if (distinct > k) break;
    }
  }
  cout << count;

  return 0;
}
