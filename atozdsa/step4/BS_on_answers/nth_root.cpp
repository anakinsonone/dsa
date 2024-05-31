#include <bits/stdc++.h>
using namespace std;

int
main ()
{
  int n, m;
  cin >> n >> m;

  // int ans = -1;
  // for (int i = 1; pow (i, n) <= m; i++)
  //   {
  //     if (pow (i, n) == m)
  //       ans = i;
  //   }
  // cout << ans;
  int ans = -1;
  int low = 1, high = m;
  while (low <= high)
    {
      int mid = (low + high) / 2;
      if (pow (mid, n) == m)
        {
          ans = mid;
          break;
        }
      if (pow (mid, n) > m)
        {
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
