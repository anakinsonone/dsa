#include <bits/stdc++.h>
using namespace std;

bool canCowsBePlaced(vector<int> &arr, int distance, int cows) {
  int totalCows = 1, prev = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] - prev >= distance) {
      totalCows++;
      prev = arr[i];
    }
    if (totalCows >= cows)
      return true;
  }
  return false;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr.begin(), arr.end());
  int low = 0, high = arr[n - 1] - arr[0];
  while (low <= high) {
    int mid = (low + high) / 2;
    if (canCowsBePlaced(arr, mid, k)) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << high;

  return 0;
}
