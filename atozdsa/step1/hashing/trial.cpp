#include <bits/stdc++.h>
using namespace std;
int
main ()
{
  int n;
  std::cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++)
    {
      std::cin >> arr[i];
    }

  std::map<int, int> mpp;
  for (int i = 0; i < n; i++)
    {
      mpp[arr[i]]++;
    }

  for (auto it : mpp)
    {
      std::cout << it.first << " --> " << it.second << std::endl;
    }

  return 0;
}
