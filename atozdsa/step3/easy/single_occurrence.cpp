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

  int xorr = 0;
  for (int i = 0; i < n; i++)
    xorr = xorr ^ arr[i];

  cout << xorr;

  return 0;
}
