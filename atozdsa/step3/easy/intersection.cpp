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

  set<int> setA, setB;
  for (int i = 0; i < n1; i++)
    setA.insert (a[i]);
  for (int i = 0; i < n2; i++)
    setB.insert (b[i]);

  vector<int> result;
  for (int ait : setA)
    {
      auto res = find (setB.begin (), setB.end (), ait);
      if (res != setB.end ())
        result.push_back (ait);
    }

  for (int i = 0; i < result.size (); i++)
    cout << result[i] << ' ';

  return 0;
}
