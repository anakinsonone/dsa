#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int largest = INT_MIN, second_largest = INT_MIN;
  int smallest = INT_MAX, second_smallest = INT_MAX;

  for (int i = 0; i < n; i++) {
    largest = max(largest, arr[i]);
    smallest = min(smallest, arr[i]);
  }

  for (int i = 0; i < n; i++) {
    if (arr[i] < largest && arr[i] > second_largest)
      second_largest = arr[i];
    if (arr[i] > smallest && arr[i] < second_smallest)
      second_smallest = arr[i];
  }
  cout << second_largest << endl << second_smallest;

  return 0;
}
