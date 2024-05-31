#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, target;
  cin >> n >> m >> target;
  vector<vector<int>> matrix(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }
  // brute
  // bool ans = false;
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     if (matrix[i][j] == target) {
  //       ans = true;
  //       break;
  //     }
  //   }
  // }
  // cout << ans;

  // better
  // bool ans = false;
  // for (int i = 0; i < n; i++) {
  //   if (!(matrix[i][0] <= target && target <= matrix[i][m - 1])) {
  //     continue;
  //   } else {
  //     int low = 0, high = m - 1;
  //     while (low <= high) {
  //       int mid = (low + high) / 2;
  //       if (matrix[i][mid] == target) {
  //         ans = true;
  //         break;
  //       } else if (matrix[i][mid] > target)
  //         high = mid - 1;
  //       else
  //         low = mid + 1;
  //     }
  //   }
  // }
  // cout << ans;

  // optimal
  bool ans = false;
  int low = 0, high = (m * n) - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    int row = (mid / m), col = (mid % m);
    if (matrix[row][col] == target) {
      ans = true;
      break;
    } else if (matrix[row][col] > target)
      high = mid - 1;
    else
      low = mid + 1;
  }
  cout << ans;

  return 0;
}
