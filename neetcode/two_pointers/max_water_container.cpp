/*
 * Max Water Container

 * You are given an integer array heights where heights[i] represents the height
 of
 * the ithith bar.

 * You may choose any two bars to form a container. Return the maximum amount of
 * water a container can store.

 * Example 1:
 * Input: height = [1,7,2,5,4,7,3,6]
 * Output: 36

 * Example 2:
 * Input: height = [2,2,2]
 * Output: 4
*/

#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> heights(n);
  for (int i = 0; i < n; i++)
    std::cin >> heights[i];

  int maxWater = 0;
  // brute force
  for (int i = 0; i < heights.size(); i++) {
    for (int j = i + 1; j < heights.size(); j++) {
      int water = std::min(heights[i], heights[j]) * (j - i);
      maxWater = std::max(maxWater, water);
    }
  }

  std::cout << maxWater;

  return 0;
}
