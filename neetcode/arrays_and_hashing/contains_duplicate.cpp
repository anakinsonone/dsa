/*
* https://neetcode.io/problems/duplicate-integer
* Given an integer array nums, return true if any value appears more than once
* in the array, otherwise return false.

* Example 1:
* Input: nums = [1, 2, 3, 3]
* Output: true

* Example 2:
* Input: nums = [1, 2, 3, 4]
* Output: false
*/

#include <bits/stdc++.h>
#include <iostream>

int main() {
  /* inputs */
  int length;
  std::cin >> length;

  std::vector<int> nums;
  for (int i = 0; i < length; i++) {
    int num;
    std::cin >> num;
    nums.push_back(num);
  }

  /* solution */
  std::map<int, int> numMap;
  for (int i = 0; i < nums.size(); i++) {
    if (numMap[nums[i]] == 1) {
      std::cout << "true\n";
      return 0;
    }
    numMap[nums[i]]++;
  }
  std::cout << "false\n";

  return 0;
}
