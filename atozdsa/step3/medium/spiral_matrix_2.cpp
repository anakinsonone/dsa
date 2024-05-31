#include <bits/stdc++.h>
using namespace std;

int
main ()
{
  int n;
  cin >> n;
  vector<vector<int> > matrix (n, vector<int> (n, 0));
  int num = 1;
  int top = 0, right = n - 1, bottom = n - 1, left = 0;

  while (top <= bottom && left <= right)
    {
      // left to right
      for (int i = left; i <= right; i++)
        {
          matrix[top][i] = num;
          num++;
        }
      top++;
      // top to bottom
      for (int i = top; i <= bottom; i++)
        {
          matrix[i][right] = num;
          num++;
        }
      right--;
      // right to left
      if (left <= right)
        {
          for (int i = right; i >= left; i--)
            {
              matrix[bottom][i] = num;
              num++;
            }
          bottom--;
        }
      // bottom to top
      if (top <= bottom)
        {
          for (int i = bottom; i >= top; i--)
            {
              matrix[i][left] = num;
              num++;
            }
          left++;
        }
    }

  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        {
          if (matrix[i][j] < 10)
            cout << " " << matrix[i][j] << " ";
          else
            cout << matrix[i][j] << ' ';
        }
      cout << endl;
    }

  return 0;
}
