/*
* Binary Search

* You are given an array of distinct integers nums, sorted in ascending order,
and an integer target.
* Implement a function to search for target within nums. If it exists, then
return its index, otherwise, return -1.
* Your solution must run in O(logn)O(logn) time.

* Example 1:
* Input: nums = [-1,0,2,4,6,8], target = 4
* Output: 3

* Example 2:
* Input: nums = [-1,0,2,4,6,8], target = 3
* Output: -1
*/

#include <iostream>
#include <vector>
int main() {
  int n, target;
  std::cin >> n;
  std::cin >> target;
  std::vector<int> nums(n, 0);
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    nums[i] = num;
  }

  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (nums[mid] == target) {
      std::cout << nums[mid];
      break;
    } else if (nums[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return 0;
}
