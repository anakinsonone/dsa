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

  vector<int> ans;
  int maxNum = INT_MIN;

  for (int i = n - 1; i >= 0; i--)
    {
      if (arr[i] > maxNum)
        {
          ans.push_back (arr[i]);
          maxNum = arr[i];
        }
    }

  for (int i = 0; i < ans.size (); i++)
    cout << ans[i] << ' ';

  return 0;
}
