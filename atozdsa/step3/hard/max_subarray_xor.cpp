#include <bits/stdc++.h>
using namespace std;

int
main ()
{
  int n, b;
  cin >> n >> b;
  int arr[n];
  int maxLen = 0;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int count = 0, xorr = 0;
  map<int, int> mpp;
  mpp[xorr]++;

  for (int i = 0; i < n; i++)
    {
      xorr = xorr ^ arr[i];

      int x = xorr ^ b;
      count += mpp[x];

      mpp[xorr]++;
    }
  cout << count;

  return 0;
}
