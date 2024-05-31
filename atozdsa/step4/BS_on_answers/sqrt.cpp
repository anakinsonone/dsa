#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  cout << int(sqrt(n)) << endl;
  int ans;
  for (int i = 1; i * i <= n; i++) {
    ans = i;
  }
  cout << ans;
  cout << pow(100, 0.5);

  return 0;
}
