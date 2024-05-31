#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(0);
  auto it = find(nums.begin(), nums.end(), 1);
  int index = it - nums.begin();
  cout << index;
  return 0;
}
