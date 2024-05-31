#include <bits/stdc++.h>

#include <climits>
using namespace std;

double median(vector<int> &a, vector<int> &b) {
  int n1 = a.size(), n2 = b.size();
  if (n1 > n2) return median(b, a);

  int n = n1 + n2;
  int left = (n + 1) / 2;

  int low = 0, high = n1;
  while (low <= high) {
    int mid1 = (low + high) / 2;
    int mid2 = left - mid1;

    int l1 = mid1 > 0 ? a[mid1 - 1] : INT_MIN;
    int l2 = mid2 > 0 ? b[mid2 - 1] : INT_MIN;
    int r1 = mid1 < n1 ? a[mid1] : INT_MAX;
    int r2 = mid2 < n2 ? b[mid2] : INT_MAX;

    if (l1 <= r2 && l2 <= r1) {
      if (n % 2 == 1)
        return max(l1, l2);
      else
        return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
    } else if (l1 > r2)
      high = mid1 - 1;
    else
      low = mid1 + 1;
  }
  return 0;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n, 0);
  vector<int> b(m, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];

  double ans = median(a, b);
  cout << ans;

  return 0;
}
