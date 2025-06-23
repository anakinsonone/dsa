/*
 *You are given a string s consisting of only uppercase english characters and
an integer k. You can choose up to k characters of the string and replace them
with any other uppercase English character.
 * After performing at most k replacements, return the length of the longest
substring which contains only one distinct character.

 * Example 1:
 * Input: s = "XYYX", k = 2
 * Output: 4
 * Explanation: Either replace the 'X's with 'Y's, or replace the 'Y's with
'X's.

 * Example 2:
 * Input: s = "AAABABB", k = 1
 * Output: 5
 * */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  int k;
  std::string s;
  std::cin >> s; // input string
  std::cin >> k; // replacements

  int res = 0;
  for (int i = 0; i < s.size(); i++) {
    std::unordered_map<char, int> charMap;
    int maxF = 0;
    for (int j = i; j < s.size(); j++) {
      // increment count for char in this substring
      charMap[s[j]]++;
      // find the char with maxFreq
      maxF = std::max(maxF, charMap[s[j]]);
      if ((j - i + 1) - maxF <= k) {
        res = std::max(res, (j - i + 1));
      }
    }
  }

  std::cout << res;

  return 0;
}
