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
  k = k % n;
  int temp[n];
  for (int i = 0; i < n; i++)
    {
      if (i + k > n - 1)
        {
          temp[i + k - n] = arr[i];
        }
      else
        {
          temp[i + k] = arr[i];
        }
    }

  for (int i = 0; i < n; i++)
    cout << temp[i] << ' ';

  return 0;
}
