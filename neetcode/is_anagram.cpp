/*
 * Given two strings s and t, return true if the two strings are anagrams of
 * each other, otherwise return false.
 *
 * An anagram is a string that contains the exact same characters as another
 * string, but the order of the characters can be different.
 *
 * Example 1:
 * Input: s = "racecar", t = "carrace"
 * Output: true
 *
 * Example 2:
 * Input: s = "jar", t = "jam"
 * Output: false
 */

#include <bits/stdc++.h>

bool isAnagram(std::string s, std::string t) {
  if (s.length() != t.length())
    return false;

  sort(s.begin(), s.end());
  sort(t.begin(), t.end());

  if (s != t)
    return false;

  return true;
}

int main() {
  std::string s, t;
  std::cin >> s >> t;

  bool result = isAnagram(s, t);
  std::cout << (result ? "true" : "false") << '\n';

  return 0;
}
