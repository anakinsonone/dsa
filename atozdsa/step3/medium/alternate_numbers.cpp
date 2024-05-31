#include <bits/stdc++.h>
using namespace std;

int
main ()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int temp[n];
  int pos = 0, neg = 1;
  for (int i = 0; i < n; i++)
    {
      if (arr[i] > 0)
        {
          temp[pos] = arr[i];
          pos += 2;
        }
      else
        {
          temp[neg] = arr[i];
          neg += 2;
        }
    }

  for (int i = 0; i < n; i++)
    {
      cout << temp[i] << ' ';
    }

  return 0;
}
