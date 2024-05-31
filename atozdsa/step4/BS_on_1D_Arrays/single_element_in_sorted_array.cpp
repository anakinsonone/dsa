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

  if (n == 1)
    return arr[0];
  if (arr[0] != arr[1])
    return arr[0];
  if (arr[n - 1] != arr[n - 1])
    return arr[n - 1];

  int low = 1, high = n - 2, ans = -1;
  while (low <= high)
    {
      int mid = (low + high) / 2;

      if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
          ans = arr[mid];
          break;
        }

      if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
          || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
        {
          low = mid + 1;
        }
      else
        {
          high = mid - 1;
        }
    }

  cout << ans;

  return 0;
}
