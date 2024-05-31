#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int
main ()
{
  // take in all inputs
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++)
    {
      int number;
      cin >> number;
      nums.push_back (number);
    }

  // populate the map with ints and their frequencies;
  map<int, int> mpp;
  for (int i = 0; i < nums.size (); i++)
    {
      mpp[nums[i]]++;
    }

  // find the numbers with max and min frequencies
  int max = 0, maxNum = 0, min = pow (10, 9), minNum = 0;
  for (auto it : mpp)
    {
      if (it.second > max)
        {
          max = it.second;
          maxNum = it.first;
        }
      if (it.second < min)
        {
          min = it.second;
          minNum = it.first;
        }
    }

  // print out the min and max
  cout << maxNum << endl << minNum;
  return 0;
}
