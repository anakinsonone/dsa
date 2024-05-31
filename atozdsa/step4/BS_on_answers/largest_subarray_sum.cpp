#include <bits/stdc++.h>

#include <algorithm>
#include <numeric>
using namespace std;

int subarrayCount(vector<int> &arr, int maxSum) {
  int subarrs = 1, sum = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (sum + arr[i] <= maxSum)
      sum += arr[i];
    else {
      subarrs++;
      sum = arr[i];
    }
  }
  return subarrs;
}

int main() {
  int n, k;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) cin >> arr[i];
  cin >> k;

  if (n == k) return *max_element(arr.begin(), arr.end());
  int low = *max_element(arr.begin(), arr.end());
  int high = accumulate(arr.begin(), arr.end(), 0);
  while (low <= high) {
    int mid = (low + high) / 2;
    int subarrsCount = subarrayCount(arr, mid);
    if (subarrsCount <= k)
      high = mid - 1;
    else
      low = mid + 1;
  }

  cout << low;

  return 0;
}
