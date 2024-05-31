#include <bits/stdc++.h>
using namespace std;

int
main ()
{
  int n, x;
  cin >> n >> x;
  vector<int> arr (n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int low = 0, high = n - 1, ans = n;
  while (low <= high)
    {
      int mid = (low + high) / 2;
      if (arr[mid] > x)
        {
          ans = mid;
          high = mid - 1;
        }
      else
        {
          low = mid + 1;
        }
    }

  cout << ans;

  return 0;
}
