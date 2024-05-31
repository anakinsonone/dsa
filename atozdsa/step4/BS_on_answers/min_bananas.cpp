#include <bits/stdc++.h>
#include <climits>
using namespace std;

int
findMax (vector<int> &arr)
{
  int maxi = INT_MIN;
  for (int i = 0; i < arr.size (); i++)
    maxi = max (maxi, arr[i]);
  return maxi;
}

long long
reqHrs (vector<int> &arr, int rate)
{
  long long totalHrs = 0;
  for (int i = 0; i < arr.size (); i++)
    totalHrs += ceil (double (arr[i]) / double (rate));
  return totalHrs;
}

int
minRate (vector<int> &arr, int h)
{
  int low = 1, high = findMax (arr);
  while (low <= high)
    {
      int mid = (low + high) / 2;
      long long totalHrs = reqHrs (arr, mid);
      if (totalHrs <= h)
        high = mid - 1;
      else
        low = mid + 1;
    }
  return low;
}

int
main ()
{
  int n, h;
  cin >> n;
  vector<int> arr (n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cin >> h;

  int ans = minRate (arr, h);
  cout << ans;

  return 0;
}
