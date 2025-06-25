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

std::string getMinSubstr(std::string s, std::string t) {
  if (s.length() < t.length()) {
    return "";
  }

  std::unordered_map<char, int> tCharMap;
  for (char c : t) {
    tCharMap[c]++;
  }

  std::string res = "";
  int minLen = INT_MAX;
  for (int i = 0; i < s.length(); i++) {
    for (int j = i; j < s.length(); j++) {
      if (j - i + 1 < t.length()) {
        continue;
      }

      std::unordered_map<char, int> subCharMap;
      for (int k = i; k <= j; k++) {
        subCharMap[s[k]]++;
      }

      bool contains = true;
      for (char c : t) {
        if (subCharMap[c] < tCharMap[c]) {
          contains = false;
          break;
        }
      }

      if (contains && j - i + 1 < minLen) {
        res = s.substr(i, j - i + 1);
        minLen = j - i + 1;
      }
    }
  }

  return res;
}

int main() {
  std::string s, t;
  std::cin >> s >> t;

  std::cout << getMinSubstr(s, t);

  return 0;
}
