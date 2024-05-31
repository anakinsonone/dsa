#include <bits/stdc++.h>
using namespace std;

long double getHigh(vector<int> &arr) {
  long double maxi = -1;
  for (int i = 1; i < arr.size(); i++) {
    long double diff = arr[i] - arr[i - 1];
    maxi = max(maxi, diff);
  }
  return maxi;
}

int possibleGasStations(vector<int> &arr, long double distance) {
  int count = 0;
  for (int i = 1; i < arr.size(); i++) {
    int diffInBetween = (arr[i] - arr[i - 1]) / distance;
    if ((arr[i] - arr[i - 1]) / distance == diffInBetween * distance) {
      diffInBetween--;
    }
    count += diffInBetween;
  }
  return count;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) cin >> arr[i];

  long double low = 0;
  long double high = getHigh(arr);
  long double diff = 1e-6;
  while (high - low > diff) {
    long double mid = (low + high) / 2.0;
    int count = possibleGasStations(arr, mid);
    if (count > k)
      low = mid;
    else
      high = mid;
  }
  cout << high;

  return 0;
}
