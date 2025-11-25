/*
 * Given an array nums of unique integers, return all the possible permutations.
 * You may return the answer in any order.

 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

 * Example 2:
 * Input: nums = [7]
 * Output: [[7]]

 * Constraints:
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 */
#include <iostream>
#include <vector>

std::vector<std::vector<int>> res;

void dfs(std::vector<int>& nums, std::vector<int>& cur,
         std::vector<bool>& chosen) {
  if (cur.size() == nums.size()) {
    res.push_back(cur);
    return;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (!chosen[i]) {
      cur.push_back(nums[i]);
      chosen[i] = true;
      dfs(nums, cur, chosen);
      cur.pop_back();
      chosen[i] = false;
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> nums(n, 0);

  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }

  std::vector<int> cur;
  std::vector<bool> chosen(n, false);
  dfs(nums, cur, chosen);

  for (auto v : res) {
    for (int i : v) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
