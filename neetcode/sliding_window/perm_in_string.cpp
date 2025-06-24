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
#include <vector>

bool checkInclusion(std::string s1, std::string s2) {
  if (s1.length() > s2.length()) {
    return false;
  }

  std::vector<int> s1Count(26, 0);
  std::vector<int> s2Count(26, 0);
  for (int i = 0; i < s1.length(); i++) {
    s1Count[s1[i] - 'a']++;
    s2Count[s2[i] - 'a']++;
  }

  int matches = 0;
  for (int i = 0; i < 26; i++) {
    if (s1Count[i] == s2Count[i]) {
      matches++;
    }
  }

  int l = 0;
  for (int r = s1.length(); r < s2.length(); r++) {
    if (matches == 26) {
      return true;
    }

    int index = s2[r] - 'a';
    s2Count[index]++;
    if (s1Count[index] == s2Count[index]) {
      matches++;
    } else if (s1Count[index] + 1 == s2Count[index]) {
      matches--;
    }

    index = s2[l] - 'a';
    s2Count[index]--;
    if (s1Count[index] == s2Count[index]) {
      matches++;
    } else if (s1Count[index] - 1 == s2Count[index]) {
      matches--;
    }
    l++;
  }

  return matches == 26;
}

int main() {
  std::string s1, s2;
  std::cin >> s1 >> s2;

  std::cout << checkInclusion(s1, s2);

  return 0;
}
