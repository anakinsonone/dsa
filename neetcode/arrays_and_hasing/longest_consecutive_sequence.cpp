/*

 * Longest Consecutive Sequence

 * Given an array of integers nums, return the length of the longest consecutive
 sequence of elements.

 * A consecutive sequence is a sequence of elements in which each element is
 exactly 1 greater than the previous element.

 * You must write an algorithm that runs in O(n) time.

 * Example 1:
 * Input: nums = [2,20,4,10,3,4,5]
 * Output: 4
 * Explanation: The longest consecutive sequence is [2, 3, 4, 5].
 *
 * Example 2:
 * Input: nums = [0,3,2,5,4,6,1,1]
 * Output: 7
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
int main() {
  int n;
  std::cin >> n;
  std::vector<int> nums(n, 0);

  for (int i = 0; i < n; i++)
    std::cin >> nums[i];

  std::set<int> numSet;
  for (auto n : nums)
    numSet.insert(n);

  int longest = 0;
  for (auto n : numSet) {
    if (numSet.find(n - 1) == numSet.end()) {
      int length = 1;
      while (numSet.find(n + length) != numSet.end()) {
        length++;
      }
      longest = std::max(longest, length);
    }
  }

  std::cout << longest;

  return 0;
}
