#include <bits/stdc++.h>
#include <climits>
using namespace std;

int
main ()
{
  int n;
  cin >> n;
  vector<int> arr (n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int low = 0, high = n - 1, ans = INT_MAX;
  while (low <= high)
    {
      int mid = (low + high) / 2;
      if (arr[low] <= arr[mid])
        {
          ans = min (ans, arr[low]);
          low = mid + 1;
        }
      else
        {
          ans = min (ans, arr[mid]);
          high = mid - 1;
        }
    }
  cout << ans;

  return 0;
}
