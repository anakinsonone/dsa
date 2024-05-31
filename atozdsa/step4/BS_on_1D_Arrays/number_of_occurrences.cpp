#include <bits/stdc++.h>
using namespace std;

int
firstOccurrence (vector<int> &arr, int n, int target)
{
  int low = 0, high = n - 1, ans = -1;
  while (low <= high)
    {
      int mid = (low + high) / 2;
      if (arr[mid] == target)
        {
          ans = mid;
          high = mid - 1;
        }
      else if (arr[mid] > target)
        {
          high = mid - 1;
        }
      else
        low = mid + 1;
    }
  return ans;
}
int
lastOccurrence (vector<int> &arr, int n, int target)
{
  int low = 0, high = n - 1, ans = -1;
  while (low <= high)
    {
      int mid = (low + high) / 2;
      if (arr[mid] == target)
        {
          ans = mid;
          low = mid + 1;
        }
      else if (arr[mid] < target)
        low = mid + 1;
      else
        high = mid - 1;
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

  ans.first = firstOccurrence (arr, n, target);
  ans.second = lastOccurrence (arr, n, target);
  if (ans.first == -1)
    {
      cout << 0;
    }
  else
    {
      cout << ans.second - ans.first + 1;
    }

  return 0;
}
