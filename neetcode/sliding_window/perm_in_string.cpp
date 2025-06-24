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
#include <iostream>
#include <string>
#include <unordered_map>

bool checkInclusion(std::string s1, std::string s2) {
  std::unordered_map<char, int> charMap;
  for (char c : s1) {
    charMap[c]++;
  }
  int need = charMap.size();

  for (int i = 0; i < s2.length(); i++) {
    std::unordered_map<char, int> charMap2;
    int count = 0;
    for (int j = i; j < s2.length(); j++) {
      char c = s2[j];
      charMap2[c]++;

      if (charMap[c] < charMap2[c]) {
        break;
      }

      if (charMap2[c] == charMap[c]) {
        count++;
      }

      if (count == need) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  std::string s1, s2;
  std::cin >> s1 >> s2;

  std::cout << (checkInclusion(s1, s2) ? "true" : "false");

  return 0;
}
