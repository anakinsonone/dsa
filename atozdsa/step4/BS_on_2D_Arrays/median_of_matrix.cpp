#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> mat[i][j];

  vector<int> flatMat;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) flatMat.push_back(mat[i][j]);

  sort(flatMat.begin(), flatMat.end());

  if ((m * n) % 2 == 1) {
    cout << flatMat[((m * n) / 2)];
  }

  return 0;
}
