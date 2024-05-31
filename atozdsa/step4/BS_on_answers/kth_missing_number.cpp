#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> k;

  // brute force
  // for (int i = 0; i < n; i++) {
  //   if (arr[i] <= k)
  //     k++;
  //   else
  //     break;
  // }
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    int missingNumbers = arr[mid] - (mid + 1);
    if (missingNumbers < k)
      low = mid + 1;
    else
      high = mid - 1;
  }

  cout << (low + k);

  return 0;
}
