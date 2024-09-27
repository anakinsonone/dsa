/*
 * Validate Parentheses

 * You are given a string s consisting of the following characters: '(', ')',
 '{',
 * '}', '[' and ']'.

 * The input string s is valid if and only if:

 *     Every open bracket is closed by the same type of close bracket.
 *     Open brackets are closed in the correct order.
 *     Every close bracket has a corresponding open bracket of the same type.

 * Return true if s is a valid string, and false otherwise.

 * Example 1:
 * Input: s = "[]"
 * Output: true
 *
 * Example 2:
 * Input: s = "([{}])"
 * Output: true

 * Example 3:
 * Input: s = "[(])"
 * Output: false
 * Explanation: The brackets are not closed in the correct order.
*/
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
int main() {
  std::string s;
  std::cin >> s;

  std::unordered_map<char, char> parens = {
      {')', '('},
      {']', '['},
      {'}', '{'},
  };

  bool res = true;
  std::stack<char> st;
  for (char c : s) {
    if (parens.find(c) != parens.end()) {
      if (st.empty()) {
        res = false;
        break;
      }

      if (st.top() != parens[c]) {
        res = false;
        break;
      }

      st.pop();
    } else {
      st.push(c);
    }
  }

  std::cout << (res ? "valid" : "invalid");

  return 0;
}
