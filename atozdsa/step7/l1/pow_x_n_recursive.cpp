#include <bits/stdc++.h>
using namespace std;

long double
raiseToPower (double x, long double ans, int n)
{
  if (n == 1)
    return ans;
  ans = ans * x;
  return raiseToPower (x, ans, n - 1);
}

int
main ()
{
  double x;
  int n;
  cin >> x >> n;

  long double ans = raiseToPower (x, x, n);

  cout << ans;

  return 0;
}
