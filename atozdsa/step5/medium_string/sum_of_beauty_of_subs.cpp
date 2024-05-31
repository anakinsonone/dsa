#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

int maximum(vector<int> &arr) {
  int maxi = INT_MIN;
  for (auto it : arr)
    if (it >= maxi)
      maxi = it;

  return maxi;
}

int minimum(vector<int> &arr) {
  int mini = INT_MAX;
  for (auto it : arr)
    if (it <= mini && it > 0)
      mini = it;

  return mini;
}

int main() {
  string s;
  cin >> s;

  int sum = 0;
  for (int i = 0; i < s.length(); i++) {
    vector<int> arr(26, 0);
    for (int j = i; j < s.length(); j++) {
      arr[s[j] - 'a']++;
      int mx = maximum(arr);
      int mn = minimum(arr);
      sum += mx - mn;
    }
  }
  cout << sum;

  return 0;
}
