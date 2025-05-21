/*
 * You are given an array of length n which was originally sorted in ascending
 * order. It has now been rotated between 1 and n times. For example, the array
 * nums = [1,2,3,4,5,6] might become:

 * [3,4,5,6,1,2] if it was rotated 4 times.
 * [1,2,3,4,5,6] if it was rotated 6 times.
 * Notice that rotating the array 4 times moves the last four elements of the
array
 * to the beginning. Rotating the array 6 times produces the original array.

 * Assuming all elements in the rotated sorted array nums are unique, return the
 * minimum element of this array.

 * A solution that runs in O(n) time is trivial, can you write an algorithm that
 * runs in O(log n) time?

 * Example 1:
 * Input: nums = [3,4,5,6,1,2]
 * Output: 1

 * Example 2:
 * Input: nums = [4,5,0,1,2,3]
 * Output: 0

 * Example 3:
 * Input: nums = [4,5,6,7]
 * Output: 4
*/

#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  int n;
  std::cin >> n;
  std::vector<int> nums = std::vector<int>(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }

  // O(n) solution
  // int low = 0, high = n - 1;
  // while (low < high) {
  //   if (nums[low] > nums[high]) {
  //     low++;
  //   }
  //   if (nums[low] < nums[high]) {
  //     break;
  //   }
  // }
  //
  // std::cout << nums[low];

  // O(log n) solution
  int res = nums[0];
  int left = 0, right = nums.size() - 1;
  while (left <= right) {
    if (nums[left] < nums[right]) {
      res = std::min(res, nums[left]);
      break;
    }
    int mid = left + (right - left) / 2;
    res = std::min(res, nums[mid]);

    if (nums[left] > nums[mid]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  std::cout << res;

  return 0;
}
