#include <bits/stdc++.h>

// #include <algorithm>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) cin >> arr[i];

  // brute force
  // vector<int> howMany(n - 1, 0);
  // for (int gasStations = 1; gasStations <= k; gasStations++) {
  //   long double maxSection = -1;
  //   int maxInd = -1;
  //   for (int i = 0; i < n - 1; i++) {
  //     long double diff = arr[i + 1] - arr[i];
  //     long double sectionLength = diff / (long double)(howMany[i] + 1);
  //     if (sectionLength > maxSection) {
  //       maxSection = sectionLength;
  //       maxInd = i;
  //     }
  //   }
  //   howMany[maxInd]++;
  // }
  //
  // long double ans = -1;
  // for (int i = 0; i < n - 1; i++) {
  //   long double diff = arr[i + 1] - arr[i];
  //   long double sectionLength = diff / (long double)(howMany[i] + 1);
  //   ans = max(ans, sectionLength);
  // }
  // cout << ans;

  // optimal 1 - using priority queue
  vector<int> howMany(n - 1, 0);
  priority_queue<pair<long double, int>> pq;

  for (int i = 0; i < n - 1; i++) {
    pq.push({arr[i + 1] - arr[i], i});
  }

  for (int i = 1; i <= k; i++) {
    auto tp = pq.top();
    pq.pop();
    int sectorIndex = tp.second;
    howMany[sectorIndex]++;
    long double initialDiff = arr[sectorIndex + 1] - arr[sectorIndex];
    long double newSectorLength =
        initialDiff / (long double)(howMany[sectorIndex] + 1);
    pq.push({newSectorLength, sectorIndex});
  }
  cout << pq.top().first;

  return 0;
}
