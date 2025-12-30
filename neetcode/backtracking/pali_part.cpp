/*
 * Given a string s, split s into substrings where every substring is a
 * palindrome. Return all possible lists of palindromic substrings.

 * You may return the solution in any order.

 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]

 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]

 * Constraints:
 * 1 <= s.length <= 20
 * s contains only lowercase English letters.
 */
#include <iostream>
#include <string>
#include <vector>

bool validPalindrome(std::string s, int l, int r) {
  while (l <= r) {
    if (s[l] != s[r]) {
      return false;
    }
    l++;
    r--;
  }
  return true;
}

std::vector<std::string> pals;

void dfs(std::string& s, std::vector<std::vector<std::string>>& res,
         std::vector<std::string>& part, int i) {
  if (i == s.size()) {
    res.push_back(part);
    return;
  }

  for (int j = i; j < s.size(); j++) {
    if (validPalindrome(s, i, j)) {
      part.push_back(s.substr(i, j - i + 1));
      dfs(s, res, part, j + 1);
      part.pop_back();
    }
  }
}

int main() {
  std::string input;
  std::cin >> input;

  std::vector<std::vector<std::string>> res;
  std::vector<std::string> part;
  dfs(input, res, part, 0);

  for (auto& p : res) {
    for (std::string s : p) {
      std::cout << s << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
