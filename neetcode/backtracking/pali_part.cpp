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

bool validPalindrome(std::string s) {
  int i = 0, j = s.length() - 1;
  while (i <= j) {
    if (s[i] != s[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

std::vector<std::string> pals;

void dfs(std::string& input, std::string& s, int i) {
  if (i == input.size()) {
    pals.push_back(s);
    return;
  }

  s.push_back(input[i]);
  dfs(input, s, i + 1);
  s.pop_back();
  dfs(input, s, i + 1);
}

int main() {
  std::string input;
  std::cin >> input;

  // std::vector<std::vector<std::string>> palindromes;
  // for (int i = 0; i < input.length(); i++) {
  //   std::vector<std::string> sub;
  //   for (int j = 0; j < input.size() - i; j++) {
  //     std::string subs = input.substr(j, i + 1);
  //     if (validPalindrome(subs)) {
  //       sub.push_back(subs);
  //     }
  //   }
  //   palindromes.push_back(sub);
  // }
  //
  // for (auto sub : palindromes) {
  //   for (std::string s : sub) {
  //     std::cout << s << ", ";
  //   }
  //   std::cout << '\n';
  // }

  std::string res;
  dfs(input, res, 0);

  for (auto p : pals) {
    std::cout << p << '\n';
  }

  return 0;
}
