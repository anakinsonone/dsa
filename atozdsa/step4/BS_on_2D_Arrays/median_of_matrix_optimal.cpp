#include <bits/stdc++.h>
using namespace std;

int numsLessThan(vector<int>& arr, int num) {
  int low = 0, high = arr.size() - 1, ans = arr.size();
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] > num) {
      ans = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  return ans;
}

int countSmallerEqual(vector<vector<int>>& mat, int n, int m, int idx) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    count += numsLessThan(mat[i], idx);
  }
  return count;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> mat[i][j];

  int low = INT_MAX, high = INT_MIN;
  for (int i = 0; i < n; i++) {
    low = min(low, mat[i][0]);
    high = max(high, mat[i][m - 1]);
  }

  int medianIdx = (m * n) / 2;
  while (low <= high) {
    int mid = (low + high) / 2;
    int smallerEqual = countSmallerEqual(mat, n, m, mid);
    if (smallerEqual <= medianIdx)
      low = mid + 1;
    else
      high = mid - 1;
  }
  cout << low;

  return 0;
}
