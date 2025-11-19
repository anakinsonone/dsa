/*Given an array nums of unique integers, return all possible subsets of nums.

 * The solution set must not contain duplicate subsets. You may return the
 * solution in any order.

 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

 * Example 2:
 * Input: nums = [7]
 * Output: [[],[7]]

 * Constraints:
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
*/
#include <iostream>
#include <vector>

void dfs(std::vector<int>& nums, int i, std::vector<int>& subset,
         std::vector<std::vector<int>>& res) {
  if (i >= nums.size()) {
    res.push_back(subset);
    return;
  }

  subset.push_back(nums[i]);
  dfs(nums, i + 1, subset, res);
  subset.pop_back();
  dfs(nums, i + 1, subset, res);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }

  std::vector<std::vector<int>> res;
  std::vector<int> subset;
  dfs(nums, 0, subset, res);

  std::cout << "total subsets: " << res.size() << '\n';
  for (auto subset : res) {
    std::cout << '[';
    for (auto num : subset) {
      if (num != subset[subset.size() - 1]) {
        std::cout << num << ",";
      } else {
        std::cout << num;
      }
    }
    std::cout << "]\n";
  }

  return 0;
}
