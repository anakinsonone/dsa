#include <bits/stdc++.h>
#include <iterator>
using namespace std;

int
main ()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int> > matrix;
  for (int i = 0; i < n; i++)
    {
      vector<int> temp;
      for (int j = 0; j < m; j++)
        {
          int num;
          cin >> num;
          temp.push_back (num);
        }
      matrix.push_back (temp);
    }

  unordered_set<int> rows;
  unordered_set<int> columns;
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
        {
          if (matrix[i][j] == 0)
            {
              rows.insert (i);
              columns.insert (j);
            }
        }
    }

  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
        {
          if (rows.find (i) != rows.end ())
            matrix[i][j] = 0;
          if (columns.find (j) != columns.end ())
            matrix[i][j] = 0;
        }
    }
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
        cout << matrix[i][j] << ' ';
      cout << endl;
    }

  return 0;
}
