/*
 * Two Integer Sum II

 * Given an array of integers numbers that is sorted in non-decreasing order.

 * Return the indices (1-indexed) of two numbers, [index1, index2], such that
 * they add up to a given target number target and index1 < index2. Note that
 * index1 and index2 cannot be equal, therefore you may not use the same element
 * twice.

 * There will always be exactly one valid solution.

 * Your solution must use O(1)O(1) additional space.

 * Example 1:
 * Input: numbers = [1,2,3,4], target = 3
 * Output: [1,2]

 * Explanation:
 * The sum of 1 and 2 is 3. Since we are assuming a 1-indexed array, index1 = 1,
 * index2 = 2. We return [1, 2].
 */

#include <iostream>
#include <utility>
#include <vector>

int main() {
  int n, target;
  std::cin >> n >> target;
  std::vector<int> numbers(n);

  for (int i = 0; i < n; i++)
    std::cin >> numbers[i];

  int left = 0, right = n - 1;
  std::pair<int, int> ans;
  while (left < right) {
    int sum = numbers[left] + numbers[right];
    if (sum == target) {
      ans = {left, right};
      break;
    } else if (sum > target) {
      right--;
    } else {
      left++;
    }
  }

  std::cout << ans.first << ", " << ans.second;

  return 0;
}
