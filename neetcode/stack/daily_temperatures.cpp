/*
 * Daily Temperatures

 * You are given an array of integers temperatures where temperatures[i]
 represents the daily temperatures on the ith day.

 * Return an array result where result[i] is the number of days after the ith
 day before a warmer temperature appears on a future day. If there is no day in
 the future where a warmer temperature will appear for the ith day, set
 result[i] to 0 instead.

 * Example 1:
 * Input: temperatures = [30,38,30,36,35,40,28]
 * Output: [1,4,1,2,1,0,0]

 * Example 2:
 * Input: temperatures = [22,21,20]
 * Output: [0,0,0]
*/

#include <iostream>
#include <stack>
#include <utility>
#include <vector>
int main() {
  int n;
  std::cin >> n;
  std::vector<int> temperatures(n);
  for (int i = 0; i < n; i++)
    std::cin >> temperatures[i];

  std::vector<int> result(n, 0);

  // brute force
  // for (int i = 0; i < temperatures.size(); i++) {
  //   int t = temperatures[i];
  //   for (int j = i + 1; j < temperatures.size(); j++) {
  //     if (temperatures[j] > t) {
  //       result[i] = j - i;
  //       break;
  //     }
  //   }
  // }

  // optimized
  std::stack<std::pair<int, int>> stack;
  for (int i = 0; i < temperatures.size(); i++) {
    int t = temperatures[i];
    while (!stack.empty() && t > stack.top().first) {
      std::pair<int, int> pair = stack.top();
      result[pair.second] = i - pair.second;
      stack.pop();
    }
    stack.push({t, i});
  }

  for (int i : result) {
    std::cout << i << ' ';
  }
  return 0;
}
