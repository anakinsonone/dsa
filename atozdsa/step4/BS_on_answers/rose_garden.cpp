#include <bits/stdc++.h>
#include <climits>
using namespace std;

int
minNoOfDays (vector<int> &arr)
{
  int mini = INT_MAX;
  for (int i = 0; i < arr.size (); i++)
    mini = min (mini, arr[i]);
  return mini;
}

int
maxNumOfDays (vector<int> &arr)
{
  int maxi = 0;
  for (int i = 0; i < arr.size (); i++)
    maxi = max (maxi, arr[i]);
  return maxi;
}

int
possibleBouquets (vector<int> &arr, int day, int roses)
{
  int bouquets = 0;
  int count = 0;
  for (int i = 0; i < arr.size (); i++)
    {
      if (arr[i] > day)
        {
          bouquets = bouquets + (count / roses);
          count = 0;
        }
      else
        count++;
    }
  bouquets += (count / roses);
  return bouquets;
}

int
main ()
{
  int n, k, m;
  cin >> n;
  vector<int> arr (n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cin >> k >> m;

  int target = m * k;
  int low = minNoOfDays (arr), high = maxNumOfDays (arr), ans = -1;
  while (low <= high)
    {
      int mid = (low + high) / 2;
      int totalBouquets = possibleBouquets (arr, mid, k);
      if (totalBouquets >= m)
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
