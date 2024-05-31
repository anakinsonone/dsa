#include <bits/stdc++.h>

using namespace std;

int expand_around_center(string s, int left, int right) {
  while (left >= 0 && right < s.length() && s[left] == s[right]) {
    left--;
    right++;
  }
  return right - left - 1;
}

int main() {
  string s;
  cin >> s;
  int n = s.length();

  int start = 0, end = 0;
  for (int i = 0; i < n; i++) {
    int odd = expand_around_center(s, i, i);
    int even = expand_around_center(s, i, i + 1);
    int max_len = max(odd, even);

    if (max_len > end - start) {
      start = i - (max_len - 1) / 2;
      end = i + max_len / 2;
    }
  }
  cout << s.substr(start, end - start + 1);

  return 0;
}
