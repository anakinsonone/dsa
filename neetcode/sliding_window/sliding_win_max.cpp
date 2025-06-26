/*You are given an array of integers nums and an integer k. There is a sliding
 * window of size k that starts at the left edge of the array. The window slides
 * one position to the right until it reaches the right edge of the array.

 * Return a list that contains the maximum element in the window at each step.

 * Example 1:
 * Input: nums = [1,2,1,0,4,2,6], k = 3
 * Output: [2,2,4,4,6]

 * Explanation:
 * Window position            Max
 * ---------------           -----
 * [1  2  1] 0  4  2  6        2
 *  1 [2  1  0] 4  2  6        2
 *  1  2 [1  0  4] 2  6        4
 *  1  2  1 [0  4  2] 6        4
 *  1  2  1  0 [4  2  6]       6
 */

#include <iostream>
#include <queue>
#include <vector>

std::vector<int> findMaxInWindows(std::vector<int> nums, int k) {
  if (k == 1) {
    return nums;
  }

  int l = 0, r = k - 1;
  std::vector<int> maximums;

  while (r < nums.size()) {
    std::priority_queue<int> pq;
    for (int i = l; i <= r; i++) {
      pq.push(nums[i]);
    }

    maximums.push_back(pq.top());

    while (pq.size()) {
      pq.pop();
    }

    r++;
    l++;
  }

  return maximums;
}

int main() {
  int n, k;
  std::cin >> n;
  std::vector<int> nums(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }
  std::cin >> k;

  std::vector<int> res = findMaxInWindows(nums, k);

  for (int r : res) {
    std::cout << r << ' ';
  }

  return 0;
}
