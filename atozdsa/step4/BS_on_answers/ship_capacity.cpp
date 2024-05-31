#include <bits/stdc++.h>
using namespace std;

int
maxWeight (vector<int> &arr)
{
  int maxi = -1;
  for (int i = 0; i < arr.size (); i++)
    maxi = max (maxi, arr[i]);
  return maxi;
}

int
weightsSum (vector<int> &arr)
{
  int sum = 0;
  for (int i = 0; i < arr.size (); i++)
    sum += arr[i];
  return sum;
}

int
daysTaken (vector<int> &arr, int shipCapacity, int days)
{
  int sum = 0, totalDays = 0;
  for (int i = 0; i < arr.size (); i++)
    {
      sum += arr[i];
      if (sum > shipCapacity)
        {
          totalDays++;
          sum = arr[i];
        }
    }
  totalDays++;
  return totalDays;
}

int
main ()
{
  int n, d;
  cin >> n >> d;
  vector<int> weights (n, 0);
  for (int i = 0; i < n; i++)
    cin >> weights[i];

  int low = maxWeight (weights), high = weightsSum (weights), ans;
  if (weights.size () == d)
    {
      cout << maxWeight (weights);
      return maxWeight (weights);
    }
  if (d == 1)
    {
      cout << weightsSum (weights);
      return weightsSum (weights);
    }
  while (low <= high)
    {
      int mid = (low + high) / 2;
      int daysNeeded = daysTaken (weights, mid, d);
      if (daysNeeded > d)
        {
          ans = mid;
          low = mid + 1;
        }
      else
        {
          ans = mid;
          high = mid - 1;
        }
    }
  cout << ans;
  return 0;
}
