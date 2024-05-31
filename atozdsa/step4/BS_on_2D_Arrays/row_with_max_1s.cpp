#include <bits/stdc++.h>

using namespace std;

int firstOccurrence(vector<int>& arr, int n, int k) {
  int low = 0, high = n - 1, ans = n;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] >= k) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }

  // Brute
  // int maxCount = 0;
  // int maxRow = -1;
  // for (int i = 0; i < n; i++) {
  //   int count = 0;
  //   for (int j = 0; j < m; j++) {
  //     if (matrix[i][j] == 1) count++;
  //   }
  //   if (count > maxCount) {
  //     maxCount = count;
  //     maxRow = i;
  //   }
  // }
  // cout << maxRow;

  // Optimal
  int maxCount = 0, index = -1;
  for (int i = 0; i < n; i++) {
    int countOnes = m - firstOccurrence(matrix[i], m, 1);
    cout << countOnes << endl;
    if (countOnes > maxCount) {
      index = i;
      maxCount = countOnes;
    }
  }
  cout << index;

  return 0;
}
