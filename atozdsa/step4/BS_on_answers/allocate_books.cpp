#include <bits/stdc++.h>

#include <algorithm>
#include <numeric>
using namespace std;

int countStudents(vector<int> &arr, int pages) {
  int students = 1, pagesCount = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (pagesCount + arr[i] <= pages)
      pagesCount += arr[i];
    else {
      students++;
      pagesCount = arr[i];
    }
  }
  return students;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) cin >> arr[i];

  int low = *max_element(arr.begin(), arr.end());
  int high = accumulate(arr.begin(), arr.end(), 0);
  while (low <= high) {
    int mid = (low + high) / 2;
    int students = countStudents(arr, mid);
    if (students <= m)
      high = mid - 1;
    else
      low = mid + 1;
  }
  cout << low;

  return 0;
}
