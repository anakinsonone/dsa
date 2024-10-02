/*
 * Three Integer Sum

 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 nums[k]]
 * where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all
 * distinct.

 * The output should not contain any duplicate triplets. You may return the
 output
 * and the triplets in any order.

 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].

 * Example 2:
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.

 * Example 3:
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
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

  std::sort(nums.begin(), nums.end());

  std::vector<std::vector<int>> ans;
  for (int i = 0; i < n; i++) {
    if (i != 0 && nums[i] == nums[i - 1])
      continue;

    int left = i + 1, right = n - 1;
    while (left < right) {
      int sum = nums[i] + nums[left] + nums[right];
      if (sum > 0) {
        right--;
      } else if (sum < 0) {
        left++;
      } else {
        ans.push_back({nums[i], nums[left], nums[right]});
        left++;
        right--;
        while (left < right && nums[left] == nums[left - 1])
          left++;
        while (left < right && nums[right] == nums[right + 1])
          right--;
      }
    }
  }

  for (auto v : ans) {
    for (auto i : v) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
