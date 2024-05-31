#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int
main ()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr;
  for (int i = 0; i < n; i++)
    {

      int num;
      cin >> num;
      arr.push_back (num);
    }

  int maxSize = 0;
  int i = 0, j = 0, sum = 0;

  while (i < n && j < n)
    {
      sum += arr[j];
      while (sum > k)
        {
          sum -= arr[i];
          i++;
        }
      if (sum == k)
        maxSize = max (maxSize, j - i + 1);
      j++;
    }

  cout << maxSize;

  return 0;
}
