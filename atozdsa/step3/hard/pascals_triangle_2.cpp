#include <bits/stdc++.h>
using namespace std;

int
main ()
{
  int n;
  cin >> n;

  vector<vector<int> > pascal;
  for (int i = 0; i <= n; i++)
    {
      vector<int> temp;
      for (int j = 0; j <= i; j++)
        {
          if (j == 0 || j == i)
            temp.push_back (1);
          else
            temp.push_back (pascal[i - 1][j - 1] + pascal[i - 1][j]);
        }
      pascal.push_back (temp);
    }
  vector<int> ans = pascal[n];
  for (int i = 0; i < ans.size (); i++)
    cout << ans[i] << ' ';

  return 0;
}
