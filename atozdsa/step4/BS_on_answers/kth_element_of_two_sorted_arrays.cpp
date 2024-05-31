#include <bits/stdc++.h>

#include <climits>
using namespace std;

int findKth(vector<int> &a, int n1, vector<int> &b, int n2, int k) {
  if (n1 > n2) return findKth(b, n2, a, n1, k);

  int low = max(0, k - n2), high = min(k, n1);
  int left = k;

  while (low <= high) {
    int mid1 = (low + high) / 2;
    int mid2 = left - mid1;

    int l1 = mid1 > 0 ? a[mid1 - 1] : INT_MIN;
    int l2 = mid2 > 0 ? b[mid2 - 1] : INT_MIN;
    int r1 = mid1 < n1 ? a[mid1] : INT_MAX;
    int r2 = mid2 < n2 ? b[mid2] : INT_MAX;

    if (l1 <= r2 && l2 <= r1) {
      return max(l1, l2);
    } else if (l1 > r2)
      high = mid1 - 1;
    else
      low = mid1 + 1;
  }
  return 0;
}

int main() {
  int n1, n2, k;
  cin >> n1;
  vector<int> a(n1, 0);
  for (int i = 0; i < n1; i++) cin >> a[i];
  cin >> n2;
  vector<int> b(n2, 0);
  for (int i = 0; i < n2; i++) cin >> b[i];
  cin >> k;

  int ans = findKth(a, n1, b, n2, k);
  cout << ans;

  return 0;
}
