#include <bits/stdc++.h>
using namespace std;

int
main ()
{
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int count = 0, maxi = 0;
  int maxIndex;
  for (int i = 0; i < n; i++)
    {
      if (arr[i] == 1)
        {
          count++;
          if (count > maxi)
            {
              maxi = count;
              maxIndex = i;
            }
        }
      else
        {
          count = 0;
        }
    }

  cout << maxi << ' ' << maxIndex;

  return 0;
}
