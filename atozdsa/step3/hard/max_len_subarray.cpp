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

  int sum = 0;
  int maxLen = 0;
  unordered_map<int, int> mpp;
  for (int i = 0; i < n; i++)
    {
      sum += arr[i];

      if (sum == 0)
        {
          maxLen = i + 1;
        }
      else if (mpp.find (sum) != mpp.end ())
        {
          maxLen = max (maxLen, i - mpp[sum]);
        }
      else
        {
          mpp[sum] = i;
        }
    }

  cout << maxLen;

  return 0;
}
