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

  int low = 0, high = n - 1;
  while (low <= high)
    {
      int mid = (low + high) / 2;
      if (nums[mid] == target)
        {
          cout << mid;
          break;
        }
      else if (target > nums[mid])
        low = mid + 1;
      else
        high = mid - 1;
    }

  return 0;
}
