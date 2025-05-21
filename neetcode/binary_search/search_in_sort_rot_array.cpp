/*
 * You are given an array of length n which was originally sorted in ascending
order. It has now been rotated between 1 and n times. For example, the array
nums = [1,2,3,4,5,6] might become:

* [3,4,5,6,1,2] if it was rotated 4 times.
* [1,2,3,4,5,6] if it was rotated 6 times.
* Given the rotated sorted array nums and an integer target, return the index of
target within nums, or -1 if it is not present.

* You may assume all elements in the sorted rotated array nums are unique,

* A solution that runs in O(n) time is trivial, can you write an algorithm that
* runs in O(log n) time?

* Example 1:
* Input: nums = [3,4,5,6,1,2], target = 1
* Output: 4

* Example 2:
* Input: nums = [3,5,6,0,1,2], target = 4
* Output: -1
*/

#include <iostream>
#include <vector>
int main() {
  int n, target;
  std::cin >> n >> target;
  std::vector<int> nums = std::vector<int>(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }

  int left = 0, right = nums.size() - 1;
  int res = -1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (nums[mid] == target) {
      res = mid;
      break;
    }

    if (nums[left] <= nums[mid]) {
      if (target > nums[mid] || target < nums[left])
        left = mid + 1;
      else
        right = mid - 1;
    } else {
      if (target < nums[mid] || target > nums[right]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
  }

  std::cout << res;

  return 0;
}
