#include <algorithm>
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

  int maxProfit = 0;
  // brute force solution
  // for (int i = 0; i < n; i++)
  //   {
  //     for (int j = i; j < n; j++)
  //       {
  //         maxProfit = max (maxProfit, arr[j] - arr[i]);
  //       }
  //   }
  // optimal solution
  int min = arr[0];
  for (int i = 1; i < n; i++)
    {
      if (arr[i] < min)
        min = arr[i];
      else
        {
          maxProfit = max (maxProfit, arr[i] - min);
        }
    }

  cout << maxProfit << endl;

  return 0;
}
