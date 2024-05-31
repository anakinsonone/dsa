#include <bits/stdc++.h>
using namespace std;

int
main ()
{

  int n, target;
  cin >> n >> target;
  vector<int> nums (n, 0);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  // better approach
  // sort (nums.begin (), nums.end ());
  // set<vector<int> > st;
  // for (int i = 0; i < n; i++)
  //   {
  //     for (int j = i + 1; j < n; j++)
  //       {
  //         set<int> hashSet;
  //         for (int k = j + 1; k < n; k++)
  //           {
  //             int reqNum = target - (nums[i] + nums[j] + nums[k]);
  //
  //             if (hashSet.find (reqNum) != hashSet.end ())
  //               {
  //                 st.insert ({ nums[i], nums[j], nums[k], reqNum });
  //               }
  //             hashSet.insert (nums[k]);
  //           }
  //       }
  //   }
  //
  // vector<vector<int> > ans (st.begin (), st.end ());

  sort (nums.begin (), nums.end ());
  vector<vector<int> > ans;
  for (int i = 0; i < n; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      for (int j = i + 1; j < n; j++)
        {
          if (j > i + 1 && nums[j] == nums[j - 1])
            continue;
          int k = j + 1;
          int l = n - 1;
          while (k < l)
            {
              int sum = nums[i] + nums[j] + nums[k] + nums[l];
              if (sum < target)
                k++;
              else if (sum > target)
                l--;
              else
                {
                  ans.push_back ({ nums[i], nums[j], nums[k], nums[l] });
                  k++;
                  l--;
                  while (k < l && nums[k] == nums[k - 1])
                    k++;
                  while (k < l && nums[l] == nums[l + 1])
                    l--;
                }
            }
        }
    }

  for (int i = 0; i < ans.size (); i++)
    {
      for (int j = 0; j < ans[0].size (); j++)
        cout << ans[i][j] << ' ';
      cout << endl;
    }
  cout << ans.size ();

  return 0;
}
