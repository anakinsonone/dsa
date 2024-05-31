#include <bits/stdc++.h>
using namespace std;

int
main ()
{
  int n1, n2;
  cin >> n1 >> n2;
  int a[n1], b[n2];
  for (int i = 0; i < n1; i++)
    cin >> a[i];
  for (int i = 0; i < n2; i++)
    cin >> b[i];

  int i = 0, j = 0;
  vector<int> uni;

  while (i < n1 && j < n2)
    {
      if (a[i] <= b[j])
        {
          if (uni.size () == 0 || a[i] != uni.back ())
            uni.push_back (a[i]);
          i++;
        }
      else
        {
          if (uni.size () == 0 || b[j] != uni.back ())
            uni.push_back (b[j]);
          j++;
        }
    }

  while (i < n1)
    {
      if (uni.size () == 0 || a[i] != uni.back ())
        uni.push_back (a[i]);
      i++;
    }

  while (j < n2)
    {
      if (uni.size () == 0 || b[j] != uni.back ())
        uni.push_back (b[j]);
      j++;
    }

  for (int i = 0; i < uni.size (); i++)
    cout << uni[i] << ' ';
}
