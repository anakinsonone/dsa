/*
 * Two Integer Sum

 *  * Given an array of integers nums and an integer target, return the indices
 i and j such that nums[i] + nums[j] == target and i != j.
 *
 * You may assume that every input has exactly one pair of indices i and j that
 * satisfy the condition.
 *
 * Return the answer with the smaller index first.
 *
 * Example 1:
 * Input:
 * nums = [3,4,5,6], target = 7
 * Output: [0,1]
 * Explanation: nums[0] + nums[1] == 7, so we return [0, 1].
 *
 * Example 2:
 * Input: nums = [4,5,6], target = 10
 * Output: [0,2]
 *
 * Example 3:
 * Input: nums = [5,5], target = 10
 * Output: [0,1]
*/
#include <bits/stdc++.h>

std::vector<int> twoSum(std::vector<int> nums, int target) {
  std::map<int, int> numMap;
  for (int i = 0; i < nums.size(); i++) {
    int diff = target - nums[i];
    if (numMap.find(diff) != numMap.end())
      return {numMap[diff], i};

    numMap[nums[i]] = i;
  }
  return {};
}

int main() {
  int n, target;
  std::cin >> n;

  std::vector<int> nums;
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    nums.push_back(num);
  }

  std::cin >> target;

  std::vector<int> answer = twoSum(nums, target);
  for (int i = 0; i < answer.size(); i++) {
    std::cout << answer[i] << " ";
  }

  return 0;
}
