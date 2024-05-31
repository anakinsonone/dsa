#include <bits/stdc++.h>
using namespace std;

int
main ()
{
  int n;
  cin >> n;
  vector<int> a (n, 0);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  // map<int, int> mpp;
  // int sum = 0;
  // int actualSum = n * (n + 1) / 2;
  // for (int i = 0; i < a.size (); i++)
  //   {
  //     sum += a[i];
  //     mpp[a[i]]++;
  //   }
  //
  // int repeated;
  // for (auto it : mpp)
  //   if (it.second == 2)
  //     repeated = it.first;
  //
  // int missing;
  // if (sum < actualSum)
  //   missing = actualSum - sum + repeated;
  // else
  //   missing = repeated - sum + actualSum;
  //
  // vector<int> ans = { repeated, missing };
  // cout << ans[0] << ' ' << ans[1];

  int sn = (n * (n + 1)) / 2;
  int s2n = (n * (n + 1) * (2 * n + 1)) / 6;
  int s = 0, s2 = 0;
  for (int i = 0; i < n; i++)
    {
      s += a[i];
      s2 += (long long)a[i] * (long long)a[i];
    }

  long long repeated = ((s - sn) + (s2 - s2n) / (s - sn)) / 2;
  long long missing = ((s2 - s2n) / (s - sn)) - repeated;
  cout << (int)missing << ' ' << (int)repeated;

  return 0;
}
