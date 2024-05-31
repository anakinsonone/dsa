#include <iostream>
#include <vector>
using namespace std;

void
insertAtPos (int n, int arr[], int num, int pos)
{
}

int
main ()
{
  int n, m;
  cin >> n >> m;
  vector<long long> a, b;
  for (int i = 0; i < n; i++)
    {
      int num;
      cin >> num;
      a.push_back (num);
    }
  for (int i = 0; i < m; i++)
    {
      int num;
      cin >> num;
      b.push_back (num);
    }

  int aptr = 0, bptr = 0;
  while (aptr < a.size () && bptr < m)
    {
      if (a[aptr] <= b[bptr])
        aptr++;
      else
        {
          a.insert (a.begin () + aptr, b[bptr]);
          aptr++;
          bptr++;
        }
    }

  for (int i = 0; i < a.size (); i++)
    cout << a[i] << ' ';
  return 0;
}
