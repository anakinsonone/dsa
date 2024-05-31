#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

int
maxNum (vector<int> &arr)
{
  int maxi = INT_MIN;
  for (int i = 0; i < arr.size (); i++)
    maxi = max (maxi, arr[i]);
  return maxi;
}

int
divsionSum (vector<int> &arr, int num)
{
  int sum = 0;
  for (int i = 0; i < arr.size (); i++)
    sum += ceil (double (arr[i]) / double (num));
  return sum;
}

int
main ()
{
  int n, limit;
  cin >> n;
  vector<int> arr (n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cin >> limit;

  int low = 1, high = maxNum (arr), ans = -1;
  while (low <= high)
    {
      int mid = (low + high) / 2;
      int divSum = divsionSum (arr, mid);
      if (divSum <= limit)
        {
          ans = mid;
          high = mid - 1;
        }
      else
        low = mid + 1;
    }
  cout << ans;

  return 0;
}
