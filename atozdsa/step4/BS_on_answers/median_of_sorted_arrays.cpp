#include <bits/stdc++.h>

#include <cmath>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n, 0);
  vector<int> b(m, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];

  vector<int> temp;
  int left = 0, right = 0;
  while (left < n && right < m) {
    if (a[left] < b[right]) {
      temp.push_back(a[left]);
      left++;
    } else {
      temp.push_back(b[right]);
      right++;
    }
  }
  while (left < n) {
    temp.push_back(a[left]);
    left++;
  }
  while (right < m) {
    temp.push_back(b[right]);
    right++;
  }

  int tempLength = temp.size();
  if (tempLength % 2 == 0) {
    int num1Idx = tempLength / 2;
    int num2Idx = num1Idx - 1;
    double ans = (double(temp[num1Idx]) + double(temp[num2Idx])) / 2.0;
    cout << ans;
  } else {
    double ans = ceil(temp.size() / 2);
    cout << temp[ans];
  }

  return 0;
}
