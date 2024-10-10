/*
 * Find Duplicate Integer

 * You are given an array of integers nums containing n + 1 integers. Each
 integer
 * in nums is in the range [1, n] inclusive.

 * Every integer appears exactly once, except for one integer which appears two
 or
 * more times. Return the integer that appears more than once.

 * Example 1:
 * Input: nums = [1,2,3,2,2]
 * Output: 2

 * Example 2:
 * Input: nums = [1,2,3,4,4]
 * Output: 4

 * Follow-up: Can you solve the problem without modifying the array nums and
 using
 * O(1)O(1) extra space?
*/

#include <iostream>
#include <vector>
int main() {
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; i++)
    std::cin >> nums[i];

  int slow = 0, fast = 0;
  while (true) {
    slow = nums[slow];
    fast = nums[nums[fast]];
    if (slow == fast)
      break;
  }

  int slow2 = 0;
  while (true) {
    slow = nums[slow];
    slow2 = nums[slow2];
    if (slow == slow2) {
      std::cout << slow;
      break;
    }
  }

  return 0;
}
