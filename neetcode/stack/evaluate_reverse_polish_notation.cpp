/*
 *Evaluate Reverse Polish Notation

 * You are given an array of strings tokens that represents a valid arithmetic
 * expression in Reverse Polish Notation.

 * Return the integer that represents the evaluation of the expression.

 *     The operands may be integers or the results of other operations.
 *     The operators include '+', '-', '*', and '/'.
 *     Assume that division between integers always truncates toward zero.

 * Example 1:
 * Input: tokens = ["1","2","+","3","*","4","-"]
 * Output: 5

 * Explanation: ((1 + 2) * 3) - 4 = 5
 */

#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::string> tokens(n);
  for (int i = 0; i < n; i++)
    std::cin >> tokens[i];

  std::stack<int> stack;
  for (std::string &t : tokens) {
    if (t == "+") {
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();
      stack.push(b + a);
    } else if (t == "-") {
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();
      stack.push(b - a);
    } else if (t == "*") {
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();
      stack.push(b * a);
    } else if (t == "/") {
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();
      stack.push(static_cast<int>(static_cast<double>(b) / a));
    } else {
      stack.push(std::stoi(t));
    }
  }

  std::cout << stack.top();

  return 0;
}
