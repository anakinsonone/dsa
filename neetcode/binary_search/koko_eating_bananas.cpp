/*
* You are given an integer array piles where piles[i] is the number of bananas
in the ith pile. You are also given an integer h, which represents the number of
hours you have to eat all the bananas.
* You may decide your bananas-per-hour eating rate of k. Each hour, you may
choose a pile of bananas and eats k bananas from that pile. If the pile has less
than k bananas, you may finish eating the pile but you can not eat from another
pile in the same hour.
* Return the minimum integer k such that you can eat all the bananas within h
hours.

* Example 1:
* Input: piles = [1,4,3,2], h = 9
* Output: 2

* Example 2:
* Input: piles = [25,10,23,4], h = 4
* Output: 25
*/

#include <algorithm>
#include <iostream>
#include <vector>

int hoursToEatAllBananas(std::vector<int> &piles, int rate) {
  int totalHours = 0;
  for (int bananas : piles) {
    totalHours += (bananas / rate);
    if (bananas % rate != 0) {
      totalHours++;
    }
  }

  return totalHours;
}

int main() {
  int n, hours;
  std::cin >> n;
  std::vector<int> piles(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> piles[i];
  }
  std::cin >> hours;

  std::sort(piles.begin(), piles.end());
  int low = 1, high = piles[piles.size() - 1];
  int minRate = high;

  while (low <= high) {
    int mid = (low + high) / 2;
    int hoursTaken = hoursToEatAllBananas(piles, mid);

    if (hoursTaken <= hours) {
      minRate = std::min(mid, minRate);
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  std::cout << minRate;

  return 0;
}
