/*
 * You are given two integer arrays nums1 and nums2 of size m and n
 * respectively, where each is sorted in ascending order. Return the median
value
 * among all elements of the two arrays.

 * Your solution must run in O(log(m+n)) time.

 * Example 1:
 * Input: nums1 = [1,2], nums2 = [3]
 * Output: 2.0
 * Explanation: Among [1, 2, 3] the median is 2.

 * Example 2:
 * Input: nums1 = [1,3], nums2 = [2,4]
 * Output: 2.5
 * Explanation: Among [1, 2, 3, 4] the median is (2 + 3) / 2 = 2.5.
 * */

#include <iostream>
#include <vector>
int main() {
  int m, n;
  std::cin >> m >> n;
  std::vector<int> nums1(m, 0);
  std::vector<int> nums2(n, 0);

  for (int i = 0; i < m; i++) {
    std::cin >> nums1[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> nums2[i];
  }

  // merge both arrays - TC - O(m + n), SC - O(m + n)
  int l = 0, r = 0;
  std::vector<int> merged;
  while (l < m && r < n) {
    if (nums1[l] <= nums2[r]) {
      merged.push_back(nums1[l]);
      l++;
    } else {
      merged.push_back(nums2[r]);
      r++;
    }
  }
  while (l < m) {
    merged.push_back(nums1[l]);
    l++;
  }
  while (r < n) {
    merged.push_back(nums2[r]);
    r++;
  }

  int index = merged.size() / 2;
  if (merged.size() % 2 != 0) {
    std::cout << merged[index];
  } else {
    int n1 = merged[index];
    int n2 = merged[index - 1];
    std::cout << float((n1 + n2) / 2.0);
  }

  return 0;
}
