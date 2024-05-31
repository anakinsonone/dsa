#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int
main ()
{
  int n;
  cin >> n;
  vector<vector<int> > matrix;
  for (int i = 0; i < n; i++)
    {
      vector<int> temp;
      for (int j = 0; j < n; j++)
        {
          int num;
          cin >> num;
          temp.push_back (num);
        }
      matrix.push_back (temp);
    }

  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < i; j++)
        {
          swap (matrix[i][j], matrix[j][i]);
        }
    }

  for (int i = 0; i < n; i++)
    {
      reverse (matrix[i].begin (), matrix[i].end ());
    }
  // I could reverse the rows first and then transpose the array
  // for (int i = 0; i < n; i++)
  //   {
  //     int jLimit = n - i - 1;
  //     for (int j = 0; j < jLimit; j++)
  //       {
  //         int disp = jLimit - j;
  //         swap (matrix[i][j], matrix[i + disp][j + disp]);
  //       }
  //   }

  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        cout << matrix[i][j] << ' ';
      cout << endl;
    }

  return 0;
}
