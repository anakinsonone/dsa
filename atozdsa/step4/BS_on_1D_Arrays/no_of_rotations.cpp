#include <bits/stdc++.h>
using namespace std;

int
main ()
{
  int n;
  cin >> n;
  vector<int> arr (n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int low = 0, high = n - 1, ans = INT_MAX, index = -1;
  while (low <= high)
    {
      int mid = (low + high) / 2;
      if (arr[low] <= arr[high])
        {
          if (arr[low] <= ans)
            {
              ans = arr[low];
              index = low;
            }
          break;
        }
      if (arr[low] <= arr[mid])
        {
          ans = min (ans, arr[low]);
          index = low;
          low = mid + 1;
        }
      else
        {
          ans = min (ans, arr[mid]);
          index = mid;
          high = mid - 1;
        }
    }

  cout << index;

  return 0;
}
