/*
 * You are given an array of integers candidates, which may contain duplicates,
 * and a target integer target. Your task is to return a list of all unique
 * combinations of candidates where the chosen numbers sum to target.

 * Each element from candidates may be chosen at most once within a combination.
 * The solution set must not contain duplicate combinations.

 * You may return the combinations in any order and the order of the numbers in
 * each combination can be in any order.

 * Example 1:
 * Input: candidates = [9,2,2,4,6,1,5], target = 8
 * Output: [
 *   [1,2,5],
 *   [2,2,4],
 *   [2,6]
 * ]

 * Example 2:
 * Input: candidates = [1,2,3,4,5], target = 7
 * Output: [
 *   [1,2,4],
 *   [2,5],
 *   [3,4]
 * ]

 * Constraints:
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
*/
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> res;

void dfs(std::vector<int>& nums, int target, std::vector<int>& cur, int i) {
  // if sum equals target insert the current subset to the result.
  if (target == 0) {
    res.push_back(cur);
    return;
  }

  // if i exceeds input array size OR current sum exceeds target, skip
  if (i == nums.size() || target < 0) {
    return;
  }

  cur.push_back(nums[i]);
  dfs(nums, target - nums[i], cur, i + 1);

  while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
    i++;
  }
  cur.pop_back();
  dfs(nums, target, cur, i + 1);
}

int main() {
  int n, target;
  std::cin >> n;
  std::vector<int> nums(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }
  std::cin >> target;

  std::sort(nums.begin(), nums.end());

  std::vector<int> cur;
  dfs(nums, target, cur, 0);

  for (int i = 0; i < res.size(); i++) {
    std::cout << '[';
    for (int j = 0; j < res[i].size(); j++) {
      if (j != res[i].size() - 1) {
        std::cout << res[i][j] << ", ";
      } else {
        std::cout << res[i][j];
      }
    }
    std::cout << "]\n";
  }

  return 0;
}
