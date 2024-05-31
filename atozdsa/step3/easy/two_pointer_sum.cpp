#include <bits/stdc++.h>
using namespace std;

int
two_sum (int arr[], int k, int n)
{
  int i = 0, j = n - 1;
  while (i < j)
    {
      if (arr[i] + arr[j] == k)
        return 1;
      else if (arr[i] + arr[j] > k)
        j--;
      else
        i++;
    }
  return 0;
}

int
main ()
{
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << (two_sum (arr, k, n) ? "true" : "false");

  return 0;
}
