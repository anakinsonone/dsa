#include <bits/stdc++.h>
using namespace std;

int
getFloor (vector<int> &arr, int n, int target)
{
  int low = 0, high = n - 1, ans = -1;
  while (low <= high)
    {
      int mid = (low + high) / 2;
      if (arr[mid] <= target)
        {
          ans = arr[mid];
          low = mid + 1;
        }
      else
        {
          high = mid - 1;
        }
    }
  return ans;
}
int
getCeiling (vector<int> &arr, int n, int target)
{
  int low = 0, high = n - 1, ans = -1;
  while (low <= high)
    {
      int mid = (low + high) / 2;
      if (arr[mid] >= target)
        {
          ans = arr[mid];
          high = mid - 1;
        }
      else
        {
          low = mid + 1;
        }
    }
  return ans;
}

int
main ()
{
  int n, target;
  cin >> n >> target;
  vector<int> arr (n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int low = 0, high = n - 1;
  pair<int, int> ans;

  ans.first = getFloor (arr, n, target);
  ans.second = getCeiling (arr, n, target);
  cout << ans.first << ' ' << ans.second;

  return 0;
}
