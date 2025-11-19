/*
 * You are given an array of distinct integers nums and a target integer target.
 * Your task is to return a list of all unique combinations of nums where the
 * chosen numbers sum to target.

 * The same number may be chosen from nums an unlimited number of times. Two
 * combinations are the same if the frequency of each of the chosen numbers is
 * the same, otherwise they are different.

 * You may return the combinations in any order and the order of the numbers in
 * each combination can be in any order.

 * Example 1:

 * Input:
 * nums = [2,5,6,9]
 * target = 9
 * Output: [[2,2,5],[9]]
 * Explanation:
 * 2 + 2 + 5 = 9. We use 2 twice, and 5 once.
 * 9 = 9. We use 9 once.

 * Example 2:
 * Input:
 * nums = [3,4,5]
 * target = 16
 * Output: [[3,3,3,3,4],[3,3,5,5],[4,4,4,4],[3,4,4,5]]

 * Example 3:
 * Input:
 * nums = [3]
 * target = 5
 * Output: []

 * Constraints:
 * All elements of nums are distinct.
 * 1 <= nums.length <= 20
 * 2 <= nums[i] <= 30
 * 2 <= target <= 30
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> res;

void dfs(std::vector<int>& nums, int target, std::vector<int>& curr, int i) {
  if (target == 0) {
    res.push_back(curr);
    return;
  }

  if (target < 0 || i >= nums.size()) {
    return;
  }

  curr.push_back(nums[i]);
  dfs(nums, target - nums[i], curr, i);
  curr.pop_back();
  dfs(nums, target, curr, i + 1);
}

int main() {
  int n, target;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }
  std::cin >> target;

  std::vector<int> curr;
  dfs(nums, target, curr, 0);

  for (auto v : res) {
    std::cout << "[";
    for (int i : v) {
      if (i != v[v.size() - 1]) {
        std::cout << i << ", ";
      } else {
        std::cout << i;
      }
    }
    std::cout << "]\n";
  }

  return 0;
}
