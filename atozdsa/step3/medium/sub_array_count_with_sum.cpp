#include <bits/stdc++.h>
using namespace std;

int
main ()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr;
  for (int i = 0; i < n; i++)
    {
      int num;
      cin >> num;
      arr.push_back (num);
    }

  // only works if all numbers are positive
  // int left = 0, right = 0, sum = 0, count = 0;
  // while (left < n && right < n)
  //   {
  //     sum += arr[right];
  //     while (sum > k)
  //       {
  //         sum -= arr[left];
  //         left++;
  //       }
  //     if (sum == k)
  //       count++;
  //     right++;
  //   }

  int count = 0;
  for (int i = 0; i < n; i++)
    {
      int sum = 0;
      for (int j = i; j < n; j++)
        {
          sum += arr[j];
          if (sum == k)
            count++;
        }
    }

  cout << count;

  return 0;
}
