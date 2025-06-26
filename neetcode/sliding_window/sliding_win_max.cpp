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

#include <deque>
#include <iostream>
#include <vector>

std::vector<int> findMaxInWindows(std::vector<int> nums, int k) {
  if (k == 1) {
    return nums;
  }

  int n = nums.size();
  std::vector<int> res(n - k + 1);
  std::deque<int> dq;
  int l = 0, r = 0;
  while (r < nums.size()) {
    // pop smaller values from front
    while (!dq.empty() && nums[dq.back()] < nums[r]) {
      dq.pop_back();
    }
    // push newer value into the window
    dq.push_back(r);

    // remove left value from the window
    if (l > dq.front()) {
      dq.pop_front();
    }

    // maintain window length
    if ((r + 1) >= k) {
      // insert the max in the output vector
      res[l] = nums[dq.front()];
      l++;
    }
    r++;
  }

  return res;
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
