#include <bits/stdc++.h>
using namespace std;

int
main ()
{
  int n;
  cin >> n;
  vector<int> arr (n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  long long maxProduct = 1;
  for (int i = 0; i < n; i++)
    {
      long long product = 1;
      for (int j = i; j < n; j++)
        {
          product *= arr[j];
          maxProduct = max (maxProduct, product);
        }
    }
  cout << maxProduct;

  return 0;
}
