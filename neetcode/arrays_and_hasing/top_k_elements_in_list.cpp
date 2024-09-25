/*
 *Top K Elements in List

 * Given an integer array nums and an integer k, return the k most frequent
 * elements within the array.

 * The test cases are generated such that the answer is always unique.

 * You may return the output in any order.

 * Example 1:
 * Input: nums = [1,2,2,3,3,3], k = 2
 * Output: [2,3]

 * Example 2:
 * Input: nums = [7,7], k = 1
 * Output: [7]
*/

#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  int n, k;
  std::cin >> n;

  std::vector<int> nums(n, 0);
  for (int i = 0; i < nums.size(); i++) {
    std::cin >> nums[i];
  }

  std::cin >> k;

  std::unordered_map<int, int> numFreq;
  for (auto &it : nums) {
    numFreq[it]++;
  }

  std::vector<std::vector<int>> ans(nums.size() + 1);
  for (auto &it : numFreq) {
    ans[it.second].push_back(it.first);
  }

  std::vector<int> result;
  for (int i = ans.size() - 1; i > 0; i--) {
    for (int n : ans[i]) {
      result.push_back(n);
      if (result.size() == k) {
        for (auto &it : result) {
          std::cout << it << '\n';
        }
        return 0;
      }
    }
  }

  return 0;
}
