#include <bits/stdc++.h>
using namespace std;

int
bs_recursive (vector<int> &arr, int low, int high, int target)
{
  if (low > high)
    return -1;
  int mid = (low + high) / 2;
  if (arr[mid] == target)
    return mid;
  else if (target > arr[mid])
    return bs_recursive (arr, mid + 1, high, target);
  else
    return bs_recursive (arr, low, mid - 1, target);
}

int
main ()
{
  int n, target;
  cin >> n >> target;
  vector<int> nums (n, 0);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  int ans = bs_recursive (nums, 0, n - 1, target);
  cout << ans;

  return 0;
}
