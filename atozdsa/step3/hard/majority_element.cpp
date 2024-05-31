#include <bits/stdc++.h>
using namespace std;

int
main ()
{

  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++)
    {
      int num;
      cin >> num;
      arr.push_back (num);
    }

  vector<int> ans;
  map<int, int> mpp;
  for (int i = 0; i < n; i++)
    {
      mpp[arr[i]]++;
    }

  for (auto it : mpp)
    {
      if (it.second > (n / 3))
        ans.push_back (it.first);
    }

  for (int i = 0; i < ans.size (); i++)
    cout << ans[i] << ' ';

  return 0;
}
