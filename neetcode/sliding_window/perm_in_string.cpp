/*You are given two strings s1 and s2.

 * Return true if s2 contains a permutation of s1, or false otherwise. That
means if a permutation of s1 exists as a substring of s2, then return true.

 * Both strings only contain lowercase letters.

 * Example 1:
 * Input: s1 = "abc", s2 = "lecabee"
 * Output: true
 * Explanation: The substring "cab" is a permutation of "abc" and is present in
 * "lecabee".

 * Example 2:
 * Input: s1 = "abc", s2 = "lecaabee"
 * Output: false
*/
#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::string s1, s2;
  std::cin >> s1 >> s2;

  std::sort(s1.begin(), s1.end());
  bool res = false;
  for (int i = 0; i < s2.size(); i++) {
    for (int j = i; j < s2.size(); j++) {
      std::string sub = s2.substr(i, j - i + 1);
      std::sort(sub.begin(), sub.end());
      if (sub == s1) {
        res = true;
        break;
      }
    }
  }

  std::cout << res;

  return 0;
}
