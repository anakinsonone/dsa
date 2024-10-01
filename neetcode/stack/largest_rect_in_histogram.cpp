/*
 * Largest Rectangle In Histogram

 * You are given an array of integers heights where heights[i] represents the
 * height of a bar. The width of each bar is 1.

 * Return the area of the largest rectangle that can be formed among the bars.

 * Note: This chart is known as a histogram.

 * Example 1:
 * Input: heights = [7,1,7,2,2,4]
 * Output: 8

 * Example 2:
 * Input: heights = [1,3,7]
 * Output: 7
*/

#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
int main() {
  int n;
  std::cin >> n;
  std::vector<int> heights(n);
  for (int i = 0; i < n; i++)
    std::cin >> heights[i];

  int maxArea = 0;
  std::stack<std::pair<int, int>> stack;

  for (int i = 0; i < heights.size(); i++) {
    int start = i;
    while (!stack.empty() && stack.top().second > heights[i]) {
      std::pair<int, int> top = stack.top();
      int index = top.first;
      int height = top.second;
      maxArea = std::max(maxArea, height * (i - index));
      start = index;
      stack.pop();
    }
    stack.push({start, heights[i]});
  }

  while (!stack.empty()) {
    int index = stack.top().first;
    int height = stack.top().second;
    maxArea =
        std::max(maxArea, height * (static_cast<int>(heights.size()) - index));
    stack.pop();
  }

  std::cout << maxArea;

  return 0;
}
