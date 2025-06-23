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

  int res = 0, left = 0, right = 0;
  std::unordered_map<char, int> charMap;
  int maxF = 0;
  while (left < s.size() && right < s.size()) {
    charMap[s[right]]++;
    maxF = std::max(maxF, charMap[s[right]]);
    int strLen = right - left + 1;
    if (strLen - maxF <= k) {
      res = std::max(res, strLen);
      right++;
    } else {
      charMap[s[left]]--;
      left++;
    }
  }

  std::cout << res;

  return 0;
}
