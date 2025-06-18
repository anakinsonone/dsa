/*
 * Given a string s, find the length of the longest substring without duplicate
characters.

 * A substring is a contiguous sequence of characters within a string.

 * Example 1:
 * Input: s = "zxyzxyz"
 * Output: 3
 * Explanation: The string "xyz" is the longest without duplicate characters.

 * Example 2:
 * Input: s = "xxxx"
 * Output: 1
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
int main() {
  std::string s;
  std::cin >> s;

  int res = 0;
  int left = 0, right = 0;
  std::unordered_set<char> charSet;
  while (right < s.size() && left < s.size()) {
    if (charSet.find(s[right]) != charSet.end()) {
      charSet.erase(s[left]);
      left++;
    } else {
      charSet.insert(s[right]);
      right++;
    }
    res = std::max(res, (int)charSet.size());
  }

  std::cout << res;

  return 0;
}
