#include <bits/stdc++.h>
using namespace std;

int
main ()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr (n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int low = 0, high = n - 1;
  bool ans = false;
  while (low <= high)
    {
      int mid = (low + high) / 2;
      if (arr[mid] == k)
        {
          ans = true;
          break;
        }
      else if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
          low++;
          high--;
          continue;
        }
      else if (arr[low] <= arr[mid])
        {
          if (arr[low] <= k && k <= arr[mid])
            high = mid - 1;
          else
            low = mid + 1;
        }
      else
        {
          if (arr[mid] <= k && k <= arr[high])
            low = mid + 1;
          else
            high = mid - 1;
        }
    }

  cout << ans;

  return 0;
}
