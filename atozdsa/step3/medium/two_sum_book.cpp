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

  map<int, int> mpp;
  for (int i = 0; i < n; i++)
    {
      mpp[arr[i]] = k - arr[i];
    }

  for (auto it : mpp)
    {
      cout << it.first << ' ' << it.second << endl;
    }

  auto res = mpp.find (1);
  cout << res->first << " " << res->second;

  return 0;
}
