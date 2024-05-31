#include <bits/stdc++.h>
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

  vector<int> answer;
  int top = 0, right = m - 1, bottom = n - 1, left = 0;
  while (top <= bottom && left <= right)
    {
      for (int i = left; i <= right; i++)
        {
          answer.push_back (matrix[top][i]);
        }
      top++;

      for (int i = top; i <= bottom; i++)
        {
          answer.push_back (matrix[i][right]);
        }
      right--;

      if (top <= bottom)
        {
          for (int i = right; i >= left; i--)
            {
              answer.push_back (matrix[bottom][i]);
            }
          bottom--;
        }

      if (left <= right)
        {
          for (int i = bottom; i >= top; i--)
            {
              answer.push_back (matrix[i][left]);
            }
          left++;
        }
    }

  for (int i = 0; i < answer.size (); i++)
    cout << answer[i] << ' ';

  return 0;
}
