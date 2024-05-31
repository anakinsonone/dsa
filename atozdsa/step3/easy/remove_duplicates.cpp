#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr.push_back(num);
  }

  int i = 0;
  for (int j = 0; j < n; j++) {
    if (arr[i] != arr[j]) {
      arr[i + 1] = arr[j];
      i++;
    }
  }

  cout << i + 1 << endl;
  arr.erase(arr.begin() + i + 1, arr.end());
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << ' ';

  return 0;
}
