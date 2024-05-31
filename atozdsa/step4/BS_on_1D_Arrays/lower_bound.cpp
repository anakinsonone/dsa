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

  for (int i = 0; i < n; i++)
    {
      if (arr[i] >= x)
        {
          cout << i;
          break;
        }
    }

  return 0;
}
