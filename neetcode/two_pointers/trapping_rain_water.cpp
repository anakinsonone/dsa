/*
 * Trapping Rain Water

 * You are given an array non-negative integers heights which represent an
 * elevation map. Each value heights[i] represents the height of a bar, which
 has a
 * width of 1.

 * Return the maximum area of water that can be trapped between the bars.

 * Example 1:
 * Input: height = [0,2,0,3,1,0,1,3,2,1]
 * Output: 9
*/

#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; i++)
    std::cin >> nums[i];

  int l = 0, r = nums.size() - 1;
  int maxL = nums[l], maxR = nums[r], sum = 0;
  while (l < r) {
    if (maxL < maxR) {
      l++;
      maxL = std::max(maxL, nums[l]);
      sum += maxL - nums[l];
    } else {
      r--;
      maxR = std::max(maxR, nums[r]);
      sum += maxR - nums[r];
    }
  }

  std::cout << sum;

  return 0;
}
