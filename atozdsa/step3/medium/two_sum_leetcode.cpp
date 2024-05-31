#include <bits/stdc++.h>
using namespace std;

int
main ()
{

  int n, target;
  cin >> n >> target;
  vector<int> arr (n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  map<int, int> mpp;

  for (int i = 0; i < n; i++)
    {
      auto res = mpp.find (target - arr[i]);
      if (res != mpp.end ())
        {
          cout << res->second << ' ' << i << endl;
          return 0;
        }
      else
        {
          mpp.insert ({ arr[i], i });
        }
    }

  return 0;
}
