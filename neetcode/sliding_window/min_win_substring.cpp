/*Given two strings s and t, return the shortest substring of s such that every
 * character in t, including duplicates, is present in the substring. If such a
 * substring does not exist, return an empty string "".

 * You may assume that the correct output is always unique.

 * Example 1:
 * Input: s = "OUZODYXAZV", t = "XYZ"
 * Output: "YXAZ"
 * Explanation: "YXAZ" is the shortest substring that includes "X", "Y", and "Z"
 * from string t.

 * Example 2:
 * Input: s = "xyz", t = "xyz"
 * Output: "xyz"

 * Example 3:
 * Input: s = "x", t = "xy"
 * Output: ""
*/
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

std::string getMinSubstr(std::string s, std::string t) {
  if (s.length() < t.length() || t.empty()) {
    return "";
  }

  std::unordered_map<char, int> countT, window;
  for (char c : t) {
    countT[c]++;
  }

  int l = 0, have = 0, need = countT.size(), resLen = INT_MAX;
  std::pair<int, int> res{-1, -1};
  for (int r = 0; r < s.length(); r++) {
    char c = s[r];
    window[c]++;

    if (countT.count(c) && window[c] == countT[c]) {
      have++;
    }

    while (have == need) {
      if (r - l + 1 < resLen) {
        res = {l, r};
        resLen = r - l + 1;
      }

      window[s[l]]--;
      if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
        have--;
      }

      l++;
    }
  }

  return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
}

int main() {
  std::string s, t;
  std::cin >> s >> t;

  std::cout << getMinSubstr(s, t);

  return 0;
}
