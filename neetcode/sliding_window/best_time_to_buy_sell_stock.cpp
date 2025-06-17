/*
 * You are given an integer array prices where prices[i] is the price of
 * NeetCoin on the ith day.
 * You may choose a single day to buy one NeetCoin and choose a different day in
 * the future to sell it.
 * Return the maximum profit you can achieve. You may choose to not make any
 * transactions, in which case the profit would be 0.

 * Example 1:
 * Input: prices = [10,1,5,6,7,1]
 * Output: 6
 * Explanation: Buy prices[1] and sell prices[4], profit = 7 - 1 = 6.

 * Example 2:
 * Input: prices = [10,8,7,5,2]
 * Output: 0
 * Explanation: No profitable transactions can be made, thus the max profit is
 */
#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  int n;
  std::cin >> n;
  std::vector<int> prices(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> prices[i];
  }

  int max_profit = 0;
  for (int i = 0; i < prices.size(); i++) {
    for (int j = i + 1; j < prices.size(); j++) {
      int profit = prices[j] - prices[i];
      max_profit = std::max(profit, max_profit);
    }
  }

  std::cout << max_profit;

  return 0;
}
