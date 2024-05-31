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

  // brute force
  // set<vector<int> > st;
  // for (int i = 0; i < n; i++)
  //   {
  //     for (int j = i + 1; j < n; j++)
  //       {
  //         for (int k = j + 1; k < n; k++)
  //           {
  //             int sum = arr[i] + arr[j] + arr[k];
  //             if (sum == 0)
  //               {
  //                 vector<int> temp = { arr[i], arr[j], arr[k] };
  //                 sort (temp.begin (), temp.end ());
  //                 st.insert (temp);
  //               }
  //           }
  //       }
  //   }

  //   better approach
  // set<vector<int> > st;
  // for (int i = 0; i < n; i++)
  //   {
  //     set<int> hashSet;
  //     for (int j = i + 1; j < n; j++)
  //       {
  //         int target = 0 - (arr[i] + arr[j]);
  //
  //         if (hashSet.find (target) != hashSet.end ())
  //           {
  //             vector<int> temp = { arr[i], arr[j], target };
  //             sort (temp.begin (), temp.end ());
  //             st.insert (temp);
  //           }
  //         hashSet.insert (arr[j]);
  //       }
  //   }

  // printing answer for brute & better approach
  // vector<vector<int> > ans (st.begin (), st.end ());
  // for (int i = 0; i < ans.size (); i++)
  //   {
  //     for (int j = 0; j < ans[0].size (); j++)
  //       {
  //         cout << ans[i][j] << ' ';
  //       }
  //     cout << endl;
  //   }

  // optimal approach
  sort (arr.begin (), arr.end ());
  vector<vector<int> > ans;

  for (int i = 0; i < n; i++)
    {
      if (i != 0 && arr[i] == arr[i - 1])
        continue;

      int j = i + 1;
      int k = n - 1;
      while (j < k)
        {
          int sum = arr[i] + arr[j] + arr[k];

          if (sum < 0)
            j++;
          else if (sum > 0)
            k--;
          else
            {
              ans.push_back ({ arr[i], arr[j], arr[k] });
              j++;
              k--;
              while (j < k && arr[j] == arr[j - 1])
                j++;
              while (j < k && arr[k] == arr[k + 1])
                k--;
            }
        }
    }

  // print answer for optimal approach
  for (int i = 0; i < ans.size (); i++)
    {
      for (int j = 0; j < ans[0].size (); j++)
        {
          cout << ans[i][j] << ' ';
        }
      cout << endl;
    }

  return 0;
}
