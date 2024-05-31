#include <bits/stdc++.h>
using namespace std;

// worst and average case time complexities are O(n^2);
// the best case can be O(n);
// we use 'didswap' to optimise the algorithm a bit,
// if it did not swap at any time, it implies that the array
// has been sorted, and there is no need to traverse further.
void bubble_sort(int nums[], int n) {
  for (int i = n - 1; i > 0; i--) {
    int didswap = 0;
    for (int j = 0; j <= i - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        int temp = nums[j + 1];
        nums[j + 1] = nums[j];
        nums[j] = temp;
        didswap = 1;
      }
    }
    if (!didswap)
      break;
  }
}

int main() {
  int n;
  cin >> n;
  int nums[n];
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  bubble_sort(nums, n);

  for (int i = 0; i < n; i++) {
    cout << nums[i] << " ";
  }
  return 0;
}
