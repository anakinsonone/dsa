/*
 * Products of Array Discluding Self

 * Given an integer array nums, return an array output where output[i] is the
 product of all the elements of nums except nums[i].

 * Each product is guaranteed to fit in a 32-bit integer.

 * Follow-up: Could you solve it in O(n)O(n) time without using the division
 operation?

 * Example 1:
 * Input: nums = [1,2,4,6]
 * Output: [48,24,12,8]

 * Example 2:
 * Input: nums = [-1,0,1,2,3]
 * Output: [0,-6,0,0,0]

*/
#include <iostream>
#include <vector>
int main() {
  int n;
  std::cin >> n;

  std::vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }

  // brute force
  // std::vector<int> res;
  // for (int i = 0; i < nums.size(); i++) {
  //   int product = 1;
  //   for (int j = 0; j < nums.size(); j++) {
  //     if (j == i)
  //       continue;
  //     product *= nums[j];
  //   }
  //   res.push_back(product);
  // }
  // for (int i : res) {
  //   std::cout << i << ' ';
  // }

  std::vector<int> res(n, 1);
  int prefix = 1;
  for (int i = 0; i < n; i++) {
    res[i] = prefix;
    prefix *= nums[i];
  }
  int postfix = 1;
  for (int i = n - 1; i >= 0; i--) {
    res[i] *= postfix;
    postfix *= nums[i];
  }

  for (int i : res) {
    std::cout << i << ' ';
  }

  return 0;
}
