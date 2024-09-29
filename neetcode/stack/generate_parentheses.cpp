/*
 * Generate Parentheses

 * You are given an integer n. Return all well-formed parentheses strings that
 you
 * can generate with n pairs of parentheses.

 * Example 1:
 * Input: n = 1
 * Output: ["()"]

 * Example 2:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]

 * You may return the answer in any order.
*/

#include <iostream>
#include <string>
#include <vector>

void backtrack(int n, int openN, int closeN, std::string current,
               std::vector<std::string> &result) {
  if (openN == closeN && openN == n) {
    result.push_back(current);
    return;
  }

  if (openN < n) {
    backtrack(n, openN + 1, closeN, current + "(", result);
  }

  if (closeN < openN) {
    backtrack(n, openN, closeN + 1, current + ")", result);
  }
}

int main() {
  int n;
  std::cin >> n;

  std::vector<std::string> ans;
  backtrack(n, 0, 0, "", ans);

  for (auto s : ans)
    std::cout << s << '\n';

  return 0;
}
