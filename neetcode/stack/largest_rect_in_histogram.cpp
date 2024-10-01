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

#include <iostream>
#include <vector>
int main() {
  int n;
  std::cin >> n;
  std::vector<int> heights(n);
  for (int i = 0; i < n; i++)
    std::cin >> heights[i];

  int maxArea = 0;
  for (int i = 0; i < n; i++) {
    int height = heights[i];
    int left = i - 1, right = i + 1;
    int count = 1;

    while (left >= 0 && heights[left] >= height) {
      count++;
      left--;
    }

    while (right < n && heights[right] >= height) {
      count++;
      right++;
    }
    std::cout << count << ' ';
    int area = height * (count);
    maxArea = std::max(maxArea, area);
  }

  std::cout << '\n' << maxArea;

  return 0;
}
