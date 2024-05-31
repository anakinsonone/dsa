#include <bits/stdc++.h>
using namespace std;

void
printArr (vector<vector<int> > arr)
{
  for (int i = 0; i < arr.size (); i++)
    {
      for (int j = 0; j < arr[0].size (); j++)
        cout << arr[i][j] << ' ';
      cout << endl;
    }
}

int
main ()
{
  int n;
  cin >> n;
  vector<vector<int> > arr (n, vector<int> (2, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2; j++)
      cin >> arr[i][j];

  vector<vector<int> > ans;
  // for (int i = 0; i < arr.size (); i++)
  //   {
  //     int l1 = arr[i][0];
  //     int r1 = arr[i][1];
  //
  //     if (!ans.empty () && r1 <= ans.back ()[1])
  //       continue;
  //
  //     for (int j = i + 1; j < n; j++)
  //       {
  //         if (arr[j][0] <= r1)
  //           r1 = max (r1, arr[j][1]);
  //         else
  //           break;
  //       }
  //     ans.push_back ({ l1, r1 });
  //   }
  for (int i = 0; i < n; i++)
    {
      if (ans.empty () || arr[i][0] > ans.back ()[1])
        ans.push_back (arr[i]);
      else
        ans.back ()[1] = max (arr[i][1], ans.back ()[1]);
    }

  printArr (ans);

  return 0;
}
