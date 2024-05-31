#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int k;
  cin >> k;

  int temp[n];
  for (int i = 0; i < n; i++) {
    if (i - k < 0)
      temp[i - k + n] = arr[i];
    else
      temp[i - k] = arr[i];
  }

  for (int i = 0; i < n; i++) {
    cout << temp[i] << ' ';
  }

  return 0;
}
