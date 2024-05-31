#include <algorithm>
#include <bits/stdc++.h>
#include <ratio>
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

  // brute
  // auto start = std::chrono::high_resolution_clock::now ();
  // for (int i = 0; i <= n; i++)
  //   {
  //     auto it = find (arr.begin (), arr.end (), i);
  //     if (it == arr.end ())
  //       {
  //         cout << i << endl;
  //         break;
  //       }
  //   }
  // auto end = std::chrono::high_resolution_clock::now ();
  // std::chrono::duration<double, std::milli> duration = end - start;
  // std::cout << "Time taken by myFunction: " << duration.count () << "ms";

  // better
  // auto start = std::chrono::high_resolution_clock::now ();
  // int size = n + 1;
  // vector<int> ans (n + 1, 0);
  // for (int i = 0; i < n; i++)
  //   {
  //     ans[arr[i]] = 1;
  //   }
  // auto end = std::chrono::high_resolution_clock::now ();
  // std::chrono::duration<double, std::milli> duration = end - start;
  // std::cout << "Time taken by myFunction: " << duration.count () << "ms"
  //           << std::endl;
  // for (int i = 0; i < ans.size (); i++)
  //   {
  //     if (ans[i] == 0)
  //       {
  //         cout << i;
  //         break;
  //       }
  //   }

  // optimal
  int expSum = n * (n + 1) / 2;
  int actSum = 0;
  for (auto it : arr)
    actSum += it;
  cout << expSum - actSum;

  return 0;
}
