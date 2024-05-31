#include <bits/stdc++.h>
using namespace std;

int findMaxIndex(vector<vector<int>>& mat, int n, int m, int col) {
  int maxi = -1, maxIndex = -1;
  for (int i = 0; i < n; i++) {
    if (mat[i][col] > maxi) {
      maxi = mat[i][col];
      maxIndex = i;
    }
  }
  return maxIndex;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> matrix[i][j];

  int low = 0, high = m - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    int maxRowIndex = findMaxIndex(matrix, n, m, mid);
    int currMid = matrix[maxRowIndex][mid];
    int left = mid - 1 > 0 ? matrix[maxRowIndex][mid - 1] : -1;
    int right = mid < m - 1 ? matrix[maxRowIndex][mid + 1] : -1;

    if (currMid > left && currMid > right) {
      cout << maxRowIndex << ' ' << mid;
      break;
    } else if (currMid > right)
      high = mid - 1;
    else
      low = mid + 1;
  }

  return 0;
}
