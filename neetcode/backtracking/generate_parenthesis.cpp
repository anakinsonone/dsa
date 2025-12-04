/*
 * You are given an integer n. Return all well-formed parentheses strings that
 * you can generate with n pairs of parentheses.

 * Example 1:
 * Input: n = 1
 * Output: ["()"]

 * Example 2:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]

 * You may return the answer in any order.

 * Constraints:
 * 1 <= n <= 7
*/
#include <iostream>
#include <string>
#include <vector>

void back_track(std::vector<std::string>& res, int open, int close, int limit,
                std::string cur) {
  if (open == close && open == limit) {
    res.push_back(cur);
    return;
  }

  if (open < limit) {
    back_track(res, open + 1, close, limit, cur + "(");
  }

  if (close < open) {
    back_track(res, open, close + 1, limit, cur + ")");
  }
}

int main() {
  int n;
  std::cin >> n;

  std::vector<std::string> res;
  std::string cur;

  back_track(res, 0, 0, n, cur);

  for (std::string s : res) {
    std::cout << '"' << s << '"' << '\n';
  }

  return 0;
}
