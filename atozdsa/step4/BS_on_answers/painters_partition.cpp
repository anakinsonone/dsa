#include <bits/stdc++.h>

#include <algorithm>
#include <numeric>
using namespace std;

int countPainters(vector<int> &arr, int hoursLimit) {
  int paintersCount = 1, hoursCount = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] + hoursCount <= hoursLimit) {
      hoursCount += arr[i];
    } else {
      paintersCount++;
      hoursCount = arr[i];
    }
  }
  return paintersCount;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) cin >> arr[i];

  int low = *max_element(arr.begin(), arr.end());
  int high = accumulate(arr.begin(), arr.end(), 0);
  while (low <= high) {
    int mid = (low + high) / 2;
    int painters = countPainters(arr, mid);
    if (painters <= k) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << low;

  return 0;
}
